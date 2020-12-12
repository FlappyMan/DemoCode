#include<stdio.h>
#include<iostream>
using namespace std;
int main(int argc,char* argv[])
{
	int i=1,j=2,k=3; 
	if(i++==1&&(++j==3||k++==3)) 
		printf("%d %d %d ",i,j,k);
	return 0;
}
