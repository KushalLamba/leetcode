#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//  Using Recursion
// int fiboaccci(int n)
// {
//     if(n==0) return 0;
//     if(n==1) return 1;
//     return fiboaccci(n-1)+fiboaccci(n-2);
// }


// Using Recursion and memorization
// int fibonacci(int n,vector<int>& dp)
// {
//     if(n==0) return 0;
//     if(n==1) return 1;
//     if(dp[n]!=-1) return dp[n];
//     dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
//     return dp[n];
// }

// Uing Bottom-Up approch
// int fibonacci(int n)
// {
//     vector<int> dp(n+1,0);
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }

// using tabular foam
int fibonacci(int n)
{
    int first=0;
    int second=1;
    if(n==0) return first;
    if(n==1) return second;
    for(int i=2;i<=n;i++)
    {
        int c=second;
        second=first+second;
        first=c;
    }
    return second;
}
int main()
{
    cout<<"Enter N: "<<endl;
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibonacci(n)<<endl;
    main();
}