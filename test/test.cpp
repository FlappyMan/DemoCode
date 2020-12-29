#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>
int fun(int a,int b)
{
    return a*b;
}

#define MAX_MEM (1024*1024*1024*5)
int main()
{
    daemon(0,0);
    int a =10;
    int b =20;
    printf("sum = %d\n",a+b);
    int c;
    int d;
    scanf("%d",&c);
    scanf("%d",&d);
    printf("plus = %d\n",fun(c,d));
    char* buf=new char[MAX_MEM];
    return 0;
}