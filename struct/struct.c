#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

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

int main(void)
{

    list_node l;
    list_node* l1 = container_of(&l,typeof(list_node),ivar);
    printf("%x %x\n",&l,l1);

    list_node* l2 = container_of(&l,typeof(list_node),cvar);
    printf("%x %x\n",&l,l2);

    list_node* l3 = container_of(&l,typeof(list_node),dvar);
    printf("%x %x\n",&l,l3);
    return 0;
}