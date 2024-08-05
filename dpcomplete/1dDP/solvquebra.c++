#include<bits/stdc++.h>
using namespace std;
// long long helper(vector<vector<int>>& nums,int pos,vector<long long>& dp)
// {
//     if(pos>=nums.size()) return 0;
//     if(dp[pos]!=-1) return dp[pos];
//     long long take=nums[pos][0]+helper(nums,pos+nums[pos][1]+1,dp);
//     long long nottake=helper(nums,pos+1,dp);
//     return dp[pos]=max(take,nottake);
// }
// long long mostPoints(vector<vector<int>>& nums)
// {
//     int n=nums.size();
//     vector<long long> dp(n,-1);
//     return helper(nums,0,dp);
// }
long long mostPoints(vector<vector<int>>& nums)
{
    int n=nums.size();
    if(n==1) return nums[0][0];
    vector<long long> dp(n,0);
    dp[n-1]=nums[n-1][0];
    for(int i=n-2;i>=0;i--)
    {
        int pos=nums[i][1]+i+1;
        long long value=nums[i][0];
        if(pos<n) dp[i]=max(value+dp[pos],dp[i+1]);
        else dp[i]=max(value,dp[i+1]);
    }
    return dp[0];
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        cin>>nums[i][0];
        cin>>nums[i][1];
    }
    cout<<mostPoints(nums);
}