#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/select.h>

#if 0
typedef int (*proc)(int ,char*);
int* getAge(int age,char* name)
{
    age = 29;
    memcpy(name,"zhangsan",20);
    printf("%d %s\n",age,name);
}

int getMaxAge(proc pro,char *name,int flag)
{
    printf("%s\n",name);
    pro(flag,name);
    return 0;
}
#else
int* getAge(int age,char* name)
{
    age = 29;
    memcpy(name,"zhangsan",20);
    printf("%d %s\n",age,name);
}

int getMaxAge(int (*proc)(int ,char*),char *name,int flag)
{
    printf("%s\n",name);
    (*proc)(flag ,name);
    return 0;
}
#endif
#define BITS_PER_LONG 32


#define FDS_BITPERLONG	(8*sizeof(long))
#define FDS_LONGS(nr)	(((nr)+FDS_BITPERLONG-1)/FDS_BITPERLONG)
#define FDS_BYTES(nr)	(FDS_LONGS(nr)*sizeof(long))

int main()
{
    char name[100] = "lisi";
    int age = getMaxAge(getAge,name,1);

    unsigned long set,n=1024;
    set = ~(~0UL << (n & (BITS_PER_LONG-1)));
    n /= BITS_PER_LONG;
    printf("n = %u set = %u\n",n,set);

    unsigned long ret = ~0UL;
    printf("~ret = %u\n",ret);

    size_t len = FDS_BYTES(589);
    printf("len = %d\n",len);

    size_t int_max = ~(size_t)0;
    printf("int max = %u\n",int_max);

    fd_set fset;
    printf("FD_SIZE = %d\n",sizeof(fset));

    return 0;
}