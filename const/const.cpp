#include<iostream>
using namespace std;
class demo
{
    public:
        static void get() 
        {
            cout<<"10"<<endl;
        }
    private:
        int a;
        int b;
};
int main()
{
    demo d;
    d.get();
    demo::get();

    int* const a = new int(10);
    //a = 10;
    *a = 20;
    int b=(int)((*(int*)0)+4); 
    cout<<b<<endl;


    return 0;
}