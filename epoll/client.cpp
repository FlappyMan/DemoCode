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
#include <string.h>
  
#define MAX_EVENTS 10  
 
 
int main()  
{  
    // socket
    struct sockaddr_in servaddr;  
    short port = 9527;  
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
    servaddr.sin_port = htons(port);
 
    if (connect(sockfd, (sockaddr *) &servaddr, sizeof(sockaddr_in)) < 0) {
        perror("connect fail");
        exit(EXIT_FAILURE);
    }
    //第一次write
    sleep(10);
    const char* buf = "1234567890";
    int len = (int)write(sockfd, buf, strlen(buf));
    if (len > 0) {
        printf("write len=%d\n", len);
    }
    sleep(10);

    //第二次write
    const char* buf1 = "hello";
    len = (int)write(sockfd, buf1, strlen(buf1));
    if (len > 0) {
        printf("write len1=%d\n", len);
    }
    sleep(10);

    //第三次write
    const char* buf2 = "world";
    len = (int)write(sockfd, buf2, strlen(buf2));
    if (len > 0) {
        printf("write len2=%d\n", len);
    }

}  