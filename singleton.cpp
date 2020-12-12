#include<iostream>
#include<string>
#include<mutex>
using namespace std;
//1、懒汉模式
class singleton
{
public:
     static singleton*GetInstance()
     {
          if (m_pInstance==NULL)
          {
               std::unique_lock<std::mutex> lock(m_mutex);
               m_pInstance = new singleton();
               cout << "singleton test" << endl;
               return m_pInstance;
          }
          return NULL;
     }
private:
     singleton(){};
     static singleton* m_pInstance;
     static std::mutex m_mutex;
};
std::mutex singleton::m_mutex;
//2、饿汉模式
class singleton_hungary
{
protected:
     singleton_hungary(){};
private:
     static singleton_hungary *p;
public:
     static singleton_hungary* instance();
};
singleton_hungary *singleton_hungary::p = new singleton_hungary();
singleton_hungary *singleton_hungary::instance()
{
     //cout << "饿汉模式" << endl;
     return p;
}
//static成员在类内的出现只是声明，需要在类的外部定义。
singleton* singleton::m_pInstance = nullptr;
int main(int argc,char *argv[])
{
     singleton *p1 = singleton::GetInstance();
     singleton *p2 = singleton::GetInstance();
     if (p1==p2)
     {
          cout << "线程安全" << endl;
     }
     else
          cout << "线程不安全" << endl;
     singleton_hungary *p3= singleton_hungary::instance();
     singleton_hungary *p4= singleton_hungary::instance();
     if (p3==p4)
     {
          cout << "线程安全" << endl;
     }
     else
          cout << "线程不安全" << endl;         
     return 0;
}