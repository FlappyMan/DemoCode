#include<stdio.h>
#include<iostream>
using namespace std;
int main(int argc,char* argv[])
{
	int i=1,j=2,k=3; 
	if(i++==1&&(++j==3||k++==3)) 
		printf("%d %d %d ",i,j,k);

	unsigned long l=~0UL;
	printf("%lu\n",l);
	l+=1;
	printf("l+1 = %lu\n",l);
	int a = -2;
	printf("n = %d\n",a);
	unsigned long l1 = ~0UL;
	unsigned long l2 = 2;
	printf("%lu %lu\n",l2-l1,l2+(~l1+1));
	return 0;
}
