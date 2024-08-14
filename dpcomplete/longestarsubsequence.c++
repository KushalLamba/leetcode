#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums,int pos,int prev,int len,int gap,vector<vector<int>>& dp)
{
     if(pos>=nums.size()) return 0;
    if(dp[pos][prev+1]!=-1) return dp[pos][prev+1];
    int take=0;
    if(len<=2 || nums[pos]-nums[prev]==gap)
    {
        gap=nums[pos]-prev;
        take=1+helper(nums,pos+1,pos,len+1,gap,dp);
    }
    int nottake=helper(nums,pos+1,prev,len,gap,dp);
    return dp[pos][prev+1]=max(take,nottake);
}
int longestArithSeqLength(vector<int>& nums) 
{
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return helper(nums,0,-1,0,-1,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<longestArithSeqLength(nums);
    return 0;
}