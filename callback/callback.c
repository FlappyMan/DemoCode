#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int (*proc)(int ,char);
void getAge(int age,char* name)
{
    age = 29;
    memcpy(name,"zhangsan",20);
    printf("%d %s\n",age,name);
}

int getMaxAge(void (*proc)(int ,char*),char *name,int flag)
{
    printf("%s\n",name);
    (*proc)(flag ,name);
    return 0;
}

int main()
{
    char name[100] = "lisi";
    getMaxAge(getAge,name,1);
    return 0;
}