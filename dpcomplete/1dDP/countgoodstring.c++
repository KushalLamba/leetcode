#include<bits/stdc++.h>
using namespace std;
// int helper(int low,int high,int zero,int one,vector<int>& dp,int pos=0,int ans=0)
// {
//     if(pos>high) return ans;
//     if(pos==high) return 1;
//     if(pos>=low) ans++;
//     if(dp[pos]!=-1) return dp[pos];
//     int zeroi=helper(low,high,zero,one,dp,pos+zero,ans);
//     int onei=helper(low,high,zero,one,dp,pos+one,ans);
//     return dp[pos]=zeroi+onei;
// }
// int countGoodStrings(int low,int high,int zero,int one)
// {
//     vector<int> dp(high+1,-1);
//     return helper(low,high,zero,one,dp);
// }
long long countGoodStrings(int low,int high,int zero,int one)
{
    vector<long long> dp(high+1,0);
    dp[0]=0;
    long long max1=0;
    for(int i=0;i<high+1;i++)
    {
        if(i>=low && i<=high)
        {
            dp[i]=1;
        }
        if(i-zero>=0) dp[i]+=dp[i-zero];
        if(i-one>=0) dp[i]+=dp[i-one];
        max1=max(max1,dp[i]);
    }
    return max1;
}
int main()
{
    int low,zero,high,one;
    cin>>low>>high>>zero>>one;
    cout<<countGoodStrings(low,high,zero,one);
}