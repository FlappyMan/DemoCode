#include<iostream>

#define F(x) ((x)*(x)+3)
int findNum(float fx,int left,int right)
{
    int cnt = 1000;
    while(100000)
    {
        if(F(i)-fx<-0.01||F(i)-fx>0.01) return i;
        if(F(i)<=right)
        {
            left = (left+right)/2;
        }else{
            right = right+(left+right)/2;
        }
        findNum(fx,left,right);
    }
}

int main(int argc,char*argv[])
{
    float fx = 133.7;
    int left=0,right=1001/2;
    int ret = findNum(fx,left,right);
    return 0;
}

