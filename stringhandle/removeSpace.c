#include<stdio.h>
#include<string.h>
//移除字符串空格并返回空格数，不用额外开辟空间
int removeSpace(char *src)
{
    int len=strlen(src);
    char *p,*q;
    p=src;
    while(*p!=' ')
    {
        p++;
    }
    q=p;
    while(1)
    {
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
//实现strstr函数并返回指针位置
char* my_strstr(const char* dest, const char* src)
{
        char* start = NULL;//用于遍历的tmp指针，每次标记遍历的起始位置
        char* substart = (char*)src;
        char* cp = (char*)dest;//cp就是用来保存首地址的
        while (*cp)
        {
             start = cp;
             while (*start != '\0' && *substart != '\0' && *start == *substart)
             {
                    start++;
                    substart++;
             }
             if (*substart == '\0')
             {
                    return cp;
             }
             substart = (char*)src;
             cp++;//cp++可以得到原起始位置的下一个位置
        }
        return NULL;
}
char* Strstr(const char* dst, const char* src)
{
    char* begin = NULL;
    char* cp = (char*)src;
    char* start = (char*)dst;
    while(*start)
    {
        begin = start;
        while(*cp!='\0'&&*begin!='\0'&&*cp==*begin)
        {
            cp++;
            begin++;
        }
        if(*cp=='\0')
        {
            return start;
        }
        cp = (char*)src;
        start++;
    }
    return NULL;
}
int main()
{
    char src[] = "hello world how are you   ";
    printf("len = %ld\n",strlen(src));
    int cnt = removeSpace(src);
    printf("%d %s\n",cnt,src);

    char a[20] = "abbbbbcdef";
    char b[10] = "bcdefg";
    printf("test = %s\n", Strstr(a, b));

    char* c=(char*)((((int*)src)+2));
    printf("c=%s\n",c);
    return 0;
}