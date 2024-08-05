#include<bits/stdc++.h>
using namespace std;
//top to down approch
// int numSquares(int n)
// {
//     if(n==0) return 0;
//     if(n<0) return INT_MAX;
//     int mincount=INT_MAX;
//     int count=0;
//     for(int i=1;i*i<=n;i++)
//     {
//         count=numSquares(n-i*i);
//         if(count!=INT_MAX) mincount=min(mincount,count+1);
//     }
//     return mincount;
// }
// bottom to up approch
int numSquares(int n)
{
    vector<int> dp(n+1);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<numSquares(n);
}