#include<bits/stdc++.h>
using namespace std;
int helper(int amount,vector<int>& coins,int sum,int pos,vector<vector<int>>& dp)
{
    if(sum>amount || pos>=coins.size()) return 0;
    if(sum==amount) return 1;
    if(dp[sum][pos]!=-1) return dp[sum][pos];
    int take=helper(amount,coins,sum+coins[pos],pos,dp);
    int nottake=helper(amount,coins,sum,pos+1,dp);
    return dp[sum][pos]=take+nottake;
}
int change1(int amount,vector<int>& coins)
{
    int n=coins.size();
    vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
    return helper(amount,coins,0,0,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    int amount;
    cin>>amount;
    cout<<change1(amount,coins);
    return 0;
}