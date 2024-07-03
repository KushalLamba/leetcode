#include<iostream>
using namespace std;
// int countnoofset(int n)
// {
//     if(n==1) return 1;
//     int count=countnoofset(n>>1);
//     count+=n&1;
//     return count;
// }
int countnoofset(int n)
{
    int count=0;
    while(n!=0)
    {
        count++;
        n=(n&(n-1));
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    cout<<countnoofset(n);
    return 0;
}