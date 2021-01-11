#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
using namespace std;
//leetcode 524
#if 0
char* findStr(const char** str,char* target,int srcSize)
{  
    if(!str||!target) return NULL;
    char *p = NULL;
    const char *tmp = NULL;
    char* dst = NULL;
    int size = 0;
    while(srcSize)
    {
        int len = 0;
        p=target;
        tmp = *str;
        while(*tmp!='\0'&&*p!='\0')
        {
            if(*tmp==*p)
            {
                len++;
                tmp++;
                p++;
            }else{
                p++;
            }
        }
        if(*tmp=='\0' && len>=size){
            if(len==size && strcmp(*str,dst)>0)
                dst = dst;
            else
                dst = (char*)*str;
        }
        size=max(len,size);
        str++;
        --srcSize;
    }
    if(dst) 
        return dst;
    return NULL;  
}
int main()
{
    const char* str[]={"ale","apple","monkey","plea","abple"};

    char target[] = "abpcplea";
    int len = sizeof(str)/sizeof(str[0]);
    char* ret=findStr(str,target,len);
    cout<<ret<<endl;
    return 0;
}
#else
typedef long LONG;
long sum(long mid,long n)
{
    long s = 0;
    n = abs(n);
    while(n)
    {
        s+=mid;
        --n;
    }
    return s;
}
int divide(int dividend, int divisor){
    LONG m = dividend;
    LONG n = divisor;
    LONG left = 0;
    LONG right = m;
    LONG ans = 0;
    while(left<right)
    {
        LONG mid = left+(right-left)/2;
        LONG ret = sum(mid,n);
        if(ret<=m){
            ans = mid;
            left = mid+1;
        }else right = mid-1;
    }
    return ans;
}

#define F(x) ((x)*(x)*(x))//x>>[0,1000]
float bianrySearch(float target)
{
    float left = 0.0;
    float right = target;
    float tmp = 1e-7;
    float f = 1e-5;
    float fot = 1e-6;

    while ((right-left>=-tmp&&right-left<=tmp)||right>left)
    {
        float mid = left+(right-left)/2;
        if(F(mid)-target>=-f&&F(mid)-target<=f) return mid;
        else if(F(mid)>target){
            right = mid-fot;
        }else if(F(mid)<target){
            left = mid+fot;
        }
    }
    return -1;
}

int main()
{
    float target = 400;
    float x = bianrySearch(target);
    cout<<x<<endl;

    int ret = divide(100,-4);
    cout<<ret<<endl;
    while(1){sleep(2);};
    return 0;
}
#endif