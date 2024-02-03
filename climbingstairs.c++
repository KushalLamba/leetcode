// leetcode question 70
#include<iostream>
using namespace std;
int helperfun(int n,int *arr)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    int first=helperfun(n-1,arr);
    int second=helperfun(n-2,arr);
    arr[n]=first+second;
    return arr[n];
}
int climbStairs(int n)
{
    int *arr=new int[n+1];
    for(int i=0;i<n+1;i++)
    {
        arr[i]=-1;
    }
    helperfun(n,arr);
}
int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n);
    return 0;
}