#include<stdio.h>
#define SUM(a,b) ((a)*(b))
static inline int fun(int a,int b)
{
    return a+b;
}
int main()
{
    int a = 10;
    int b = 20;
    fun(a,b);
    SUM('a','b');
    printf("%d\n",SUM('a',1));
    return 0;
}