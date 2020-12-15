#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

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
int main()
{
    char name[100] = "lisi";
    int age = getMaxAge(getAge,name,1);
    return 0;
}