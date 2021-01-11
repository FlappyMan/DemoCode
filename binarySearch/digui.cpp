#include<iostream>
using namespace std;
double quickMul(double x, long long N) {
    if (N == 0) {
        return 1.0;
    }
    double y = quickMul(x, N / 2);
    return N % 2 == 0 ? y * y : y * y * x;
}
// double quickMul(double x,int n)
// {
//     double sum = 1.0;
//     for(int i=0;i<n;++i)
//     {
//         sum*=x;
//     }
//     return sum;
// }

double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
}

int main()
{
    double ret = myPow(2,5);
    cout<<ret<<endl;
    return 0;
}