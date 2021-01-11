#include<iostream>
using namespace std;
int search(int *a,int target,int left,int right)
{
#if 1
    if(left<=right)
    {
        int mid = (left+right)/2;
        if(a[mid]==target) return mid;
        else if(a[mid]<target){
            return search(a,target,mid+1,right);
        }else if(a[mid]>target){
            return search(a,target,left,mid-1);
        }
    }
    return -1;
#else
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(a[mid] == target) return mid;
        else if(a[mid]>target){
            right = mid-1;
        }else if(a[mid]<target){
            left = mid+1;
        }
    }
    return -1;
#endif
}
int main()
{
    int a[] = { 3,5,11,17,21,23,28,30,32,50,64,78,81,95,101};
    int target = 17;
    int left = 0;
    int right = sizeof(a)/sizeof(a[0]);
    int ret = search(a,target,left,right);
    cout<<ret<<endl;
    return 0;
}