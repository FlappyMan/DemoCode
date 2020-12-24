#include<iostream>
extern int a;
extern int fun(int a,int b);
extern void get();
using namespace std;
int main()
{
    cout<<a<<endl;
    int sum = fun(10,20);
    cout<<sum<<endl;

    int b;
    cout<<b<<endl;
    get();
    return 0;
}