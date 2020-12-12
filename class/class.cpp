#include<iostream>
using namespace std;

class A
{
    public:
        int a;
};

class B:public A
{
    public:
        int a;
};

class C:public A
{
    public:
        int a;
};

class D:public B,public C
{
    public:
        int a;
};
int main002()
{
    D d;
    d.a = 1;

    d.B::a = 2;
    //d.B::A::a = 3;

    d.C::a = 4;

    cout<<"sizeof A:"<<sizeof(A)<<endl;
    cout<<"sizeof B:"<<sizeof(B)<<endl;
    cout<<"sizeof C:"<<sizeof(C)<<endl;
    cout<<"sizeof D:"<<sizeof(D)<<endl;
    return 0;
}