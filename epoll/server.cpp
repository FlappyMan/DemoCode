#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
 
 
#define MAX_EVENTS 10
 
static void setnonblocking(int fd) {
    int flag = fcntl(fd, F_GETFL, 0);
    if (flag < 0) {
        perror("fcntl F_GETFL:");
        return;
    }
    if (fcntl(fd, F_SETFL, flag | O_NONBLOCK) < 0) {
        perror("fcntl F_SETFL:");
    }
}
 
static int epoll_add(int efd, int sock) {
    struct epoll_event ev;
    ev.events = EPOLLIN|EPOLLET;
    ev.data.fd = sock;
    if (-1 == epoll_ctl(efd, EPOLL_CTL_ADD, sock, &ev)) {
        perror("epoll_ctl: sock");
        return 1;
    }
    return 0;
}
 
static void epoll_write(int efd, int sock, bool enable) {
    struct epoll_event ev;
    ev.events = EPOLLIN | (enable ? EPOLLOUT : 0);
    ev.data.fd = sock;
    epoll_ctl(efd, EPOLL_CTL_MOD, sock, &ev);
}
 
static void epoll_del(int efd, int sock) {
    epoll_ctl(efd, EPOLL_CTL_DEL, sock , NULL);
}
 
int main()
{
    // socket
    int listenfd;
    struct sockaddr_in servaddr;
    short port = 9527;
  
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
 
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    setnonblocking(listenfd);
    int res = bind(listenfd, (sockaddr *)&servaddr, sizeof(sockaddr_in));
    if (0 == res)
        printf("server bind success, 0.0.0.0:%d\n", port);
    else {
        perror("bind fail");
        exit(EXIT_FAILURE);
    }
    res = listen(listenfd, 100);
    printf("listenfd = %d\n",listenfd);
    if (0 == res)
        printf("server listen success\n");
    else {
        perror("listen fail");
        exit(EXIT_FAILURE);
    }
 
 
    // epoll
    struct epoll_event ev, events[MAX_EVENTS];
    int epollfd = epoll_create(10);
    if (-1 == epollfd) {
        perror("epoll_create fail");
        exit(EXIT_FAILURE);
    }
 
    ev.events = EPOLLIN; // LT 
    ev.data.fd = listenfd;
    if (-1 == epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev)) {
        perror("epoll_ctl: listenfd fail");
        exit(EXIT_FAILURE);
    }
 fetch_events:
    for (;;) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (-1 == nfds) {
            perror("epoll_wait fail");
            exit(EXIT_FAILURE);
        }
        send_events:
        for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == listenfd) {
                struct sockaddr_in sa;
                int size;
                int connfd = accept(listenfd, (sockaddr*)&sa, (socklen_t*)&size);
                if (-1 == connfd) {
                    perror("accept fail");
                    continue;
                }
                printf("client addr = %s %d\n",inet_ntoa(sa.sin_addr),ntohs(sa.sin_port));
                setnonblocking(connfd);
                epoll_add(epollfd, connfd);
                printf("connfd:%d\n", connfd);
            }
            else if (events[n].events & EPOLLIN) {
                char buf[128] = {0};
                int fd = events[n].data.fd;
                size_t count = 128;
                int len = (int)read(fd, buf, count);
                if (len > 0) {
                    printf("read len=%d buf=%s\n", len, buf);
                    //epoll_write(epollfd, fd, false);
                }
                else if (len < 0) {
                    switch(errno) {
                    case EINTR:
                    case EAGAIN:
                        printf("try again\n");
                        //epoll_write(epollfd, fd, false);
                        break;
                    default:
                        epoll_del(epollfd, fd);
                        close(fd);
                        printf("game over len<1\n");
                    }
                }
                else if (len == 0) {
                    epoll_del(epollfd, fd);
                    close(fd);
                    //printf("game over len==0\n");
                }
                // ev.data.fd=fd;
                // ev.events=EPOLLIN|EPOLLET;
                // epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&ev);
            }
            else {
                // pass
            }
        }
    }
 
}