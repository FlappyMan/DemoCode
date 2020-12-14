#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<limits.h>

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER )

#define container_of(ptr, type, member) ({ \
const typeof( ((type *)0)->member ) *__mptr = (ptr); \
(type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct list_node
{
    int ivar;
    char cvar;
    double dvar;
    struct list_node *next;
}list_node;

#define EP_MAX_EVENTS (INT_MAX / sizeof(struct epoll_event))

int main(void)
{

    list_node l;
    list_node* l1 = container_of(&l,typeof(list_node),next);
    printf("%x %x\n",&l,l1);

    list_node* l2 = container_of(&l,typeof(list_node),next);
    printf("%x %x\n",&l,l2);

    list_node* l3 = container_of(&l,typeof(list_node),next);
    printf("%x %x\n",&l,l3);

    printf("%d\n",EP_MAX_EVENTS);
    return 0;
}