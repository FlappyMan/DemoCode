#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<limits.h>


struct list_head {
	struct list_head *next, *prev;
};

struct epitem {

	/* List header used to link this structure to the eventpoll ready list */
	struct list_head rdllink;
    char data;

};

struct test{
    char c;
    int b;
    struct list_head head;
};

typedef struct list_node
{
    int ivar;
    int iCnt;
    int i;
    int m;
    int n;
    struct list_head rdllist;
}list_node;

//************************************************************
//************************************************************

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER )

#define container_of(ptr, type, member) ({ \
const typeof( ((type *)0)->member ) *__mptr = (ptr); \
(type *)( (char *)__mptr - offsetof(type,member) );})


#define EP_MAX_EVENTS (INT_MAX / sizeof(struct epoll_event))

#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

/**
 * list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
 * @pos:	the type * to use as a loop cursor.
 * @n:		another type * to use as temporary storage
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 */
#define list_for_each_entry_safe(pos, n, head, member)			\
	for (pos = list_entry((head)->next, typeof(*pos), member),	\
		n = list_entry(pos->member.next, typeof(*pos), member);	\
	     &pos->member != (head);					\
	     pos = n, n = list_entry(n->member.next, typeof(*n), member))


static inline int list_empty(const struct list_head *head)
{
	return head->next == head;
}

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

static inline void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}


int fun()
{
    return 2==1;
}

int main(void)
{

    list_node l;
    list_node* l1 = container_of(&l,typeof(list_node),rdllist);
    printf("%x %x\n",&l,l1);

    struct epitem it;
    struct epitem* item = container_of(&it,typeof(struct epitem),rdllink);
    printf("%x %x\n",&l,item);

    size_t off = offsetof(struct list_node,rdllist);
    printf("member_off : %d struct size : %d size : %d\n",
    off,sizeof(struct list_node),sizeof(l.rdllist));

    off = offsetof(struct epitem,rdllink);
    printf("member_off : %d struct size : %d size : %d\n",
    off,sizeof(struct epitem),sizeof(it.rdllink));

    printf("%d\n",EP_MAX_EVENTS);

    off = offsetof(struct test,head);
    printf("empty struct : %d off=%d\n",sizeof(struct test),off);
    printf("unsigned long %d %d\n",sizeof(unsigned long),sizeof(unsigned int));


    LIST_HEAD(txlist);
    
    struct epitem epi = {
        .data = 'a',
        .rdllink = LIST_HEAD_INIT(epi.rdllink)
    };

    struct epitem epi2 = {
        .data = 'b',
        .rdllink = LIST_HEAD_INIT(epi.rdllink)
    };

    struct epitem epi3 = {
        .data = 'c',
        .rdllink = LIST_HEAD_INIT(epi.rdllink)
    };

    list_add(&epi.rdllink,&txlist);
    list_add(&epi2.rdllink,&txlist);
    list_add(&epi3.rdllink,&txlist);

    struct epitem *_epi;
    struct epitem *tmp;
    struct list_head *head = &txlist;

    typeof(((struct list_node*)0)->rdllist)* _mptr = head;

    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(struct list_head));

    printf("txlist head  : cur %p next %p prev %p\n",&txlist,txlist.next,txlist.prev);
    printf("epi3   list  : cur %p next %p prev %p\n",&epi3.rdllink,(&epi3.rdllink)->next,(&epi3.rdllink)->prev);
    printf("epi2   list  : cur %p next %p prev %p\n",&epi2.rdllink,(&epi2.rdllink)->next,(&epi2.rdllink)->prev);
    printf("epi    list  : cur %p next %p prev %p\n",&epi.rdllink,(&epi.rdllink)->next,(&epi.rdllink)->prev);

    list_for_each_entry_safe(_epi, tmp, head, rdllink)
    {
        printf("_epi->data = %d\n",_epi->data);
    }
    system("pause");
    return 0;
}