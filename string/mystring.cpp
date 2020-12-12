#include<iostream>
#include<string.h>
using namespace std;
class myString
{
    public:
        myString(){};
        ~myString(){};
        myString(const char* str)
        {
            if(!str)
            {
                data=new char[1];
                *data='\0';
            }else{
                int len = strlen(str)+1;
                data = new char[len];
                strcpy(data,str);
            }
        }
        myString(const myString& str)
        {
            int len = strlen(str.data)+1;
            data = new char[len];
            strcpy(data,str.data);
        }
        myString& operator=(const myString& str)
        {
            if(this==&str)return *this;
            int len = strlen(str.data)+1;
            data = new char[len];
            strcpy(data,str.data);
            return *this;
        }
        friend ostream& operator<<(ostream& os,myString& str);
    private:
        char* data;
        int length;
};
class test
{
    public:
        test()
        {
            a=1;
            b=2;
            cout<<"2"<<endl;
        }
        test(int a,int b=2)
        {
            cout<<"1"<<endl;
        }
    private:
        int a;
        int b;
};
ostream& operator<<(ostream& os,myString& str)
{
    os << str.data;
	return os;
}
int main()
{
    char c[] = "hello world";
    myString str(c);
    cout<<str<<endl;
    myString str1(str);
    cout<<str1<<endl;
    myString str2;
    str2=str1;
    cout<<str2<<endl;
    test t;
    test t1(1);
    return 0;
}