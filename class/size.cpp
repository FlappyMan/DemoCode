#include <iostream>
using namespace std;

class B //基类
{
public:
    B()
    {
        cout << "B" << endl;
    }
    ~B()
    {
        cout << "~B()" << endl;
    }
// private:
//     int a;
};
class C1 : public B
{
public:
    C1()
    {
        cout << "C1()" << endl;
    }
    ~C1()
    {
        cout << "~C1()" << endl;
    }
// private:
//     int a;
};
class C2 : public B
{
public:
    C2()
    {
        cout << "C2()" << endl;
    }
    ~C2()
    {
        cout << "~C2()" << endl;
    }
// private:
//     int b;
};
class D :public C1, public C2
{
public:
    D()
    {
        cout << "D()" << endl;
    }
    ~D()
    {
        cout << "~D()" << endl;
    }
private:
    int c;
    static int b;
};
class empty{};

void f()
{
    empty a,b;
    if(&a==&b)cout<<"error"<<endl;

    empty* p1 = new empty;
    empty* p2 = new empty;
    if(p1==p2) cout<<"right"<<endl;
}
int main003()
{
    cout << sizeof(B) << endl;
    cout << sizeof(C1) << endl;
    cout << sizeof(C2) << endl;
    cout << sizeof(D) << endl;

    f();
    return 0;
}