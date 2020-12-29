#include<stdio.h>
struct list_head {
	struct list_head *next, *prev;
};
int main()
{
    char a = 'g';
    char *b = &a;
    char *c = &b;
    printf("%d\n",sizeof(struct list_head));
    printf("%d %d\n",sizeof(void*),sizeof(unsigned long));
    return 0;
}