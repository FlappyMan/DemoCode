#include<iostream>
using namespace std;
struct s3
{
    char k;
    int c;
    int i; //12
};

struct s4
{
    s3 a[2]; //24
    double i[5]; //40
};

int main001()
{
    cout<<sizeof(s4)<<endl;
    return 0;
}