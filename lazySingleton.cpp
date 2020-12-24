#include<iostream>
using namespace std;
class singleton
{
    public:
        static singleton& getInstance()
        {
            static singleton single;
            return single;       
        }
    private:
        // static singleton* m_singleton;
        singleton(){cout<<"constructor"<<endl;};
        // singleton(singleton*){};
};
int main()
{
    singleton& s1 = singleton::getInstance();
    singleton& s2 = singleton::getInstance();
    return 0;
}