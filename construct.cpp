#include<stdio.h>
#include<iostream>
using namespace std;
class Date
{
public:

    //1和2两个构造函数构成函数重载
    //函数重载：函数名相同，参数列表不同（参数个数，参数类型）
    //返回值可同可不同。
    void show()
    {
        cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
    }
    static Date* getInstance()
    {
        Date *date;
        if(!date)
        {
            date = new Date;
        }
        return date;

    }
private:
    int _year;
    int _month;
    int _day;
    Date(){};
    static Date* date;
};

int main(int argc,char* argv[])
{
    // Date d1;//会调用无参构造函数
    // Date d2(2018,7,31);//会调用有参构造函数
    // d2.show();
    Date::getInstance();
	return 0;
}
