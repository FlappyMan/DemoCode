#include<stdlib.h>
int removeSpace(char *src)
{
    int len=strlen(src);
    char *p,*q;
    int cnt = 0;
    p=src;
    while(1)
    {
        while(*p!=' ')
        {
            p++;
        }
        q=p;
        while(*q==' ') 
        {
            q++; 
            if (*q=='\0') 
	        break;
        }        
        if(*q=='\0')
        {
            *p=*q;
            break;
        }else{
            *p=*q;
            *q=' ';
            q++;
            p++;
        }
    }
    return len-strlen(src);	
}
int main()
{
    char src[] = "hello world how are you";
    int cnt = removeSpace(src);
    printf("%d %s\n",cnt,src);
    int a[]={1,2,3,4};
    int count = sizeof(a)/sizeof(int);
    printf("%d\n",count);
    return 0;
}