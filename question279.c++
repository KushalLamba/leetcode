#include<bits/stdc++.h>
using namespace std;
// simple approch recursion 
// int numSquares(int n)
// {
//     if(n==0) return 0;
//     int count=n;
//     for(int i=1;i*i<=n;i++)
//     {
//        count=min(count,1+numSquares(n-i*i));
//     }
//     return count;
// }
// int main()
// {
//     cout<<"Enter Value of n: "<<endl;
//     int n;
//     cin>>n;
//     cout<<numSquares(n);
// }


// recursion+ memorization
// int numSquares(int n,vector<int>& dp)
// {
//     if(n==0) return 0;
//     if(dp[n]!=-1) return dp[n];
//     int count=n;
//     for(int i=1;i*i<=n;i++)
//     {
//        count=min(count,1+numSquares(n-i*i,dp));
//     }
//     dp[n]=count;
//     return dp[n];
// }
// int main()
// {
//     cout<<"Enter Value of n: "<<endl;
//     int n;
//     cin>>n;
//     vector<int> dp(n+1,-1);
//     cout<<numSquares(n,dp);
// }
// using dp
// int numSquares(int n)
// {
//     vector<int> dp(n+1,INT_MAX);
//     dp[0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j*j<=n;j++)
//         {
//             int temp=j*j;
//             if(i-temp>=0) dp[i]=min(dp[i],1+dp[i-temp]);
//         }
//     }
//     return dp[n];
// }
// int main()
// {
//     cout<<"Enter Value of n: "<<endl;
//     int n;
//     cin>>n;
//     cout<<numSquares(n);
// }