#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums,int i,int j,vector<vector<int>>& dp)
{
    if(i>=j) return nums[i];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(nums[i]-helper(nums,i+1,j,dp),nums[j]-helper(nums,i,j-1,dp));
}
bool predictTheWinner(vector<int>& nums)
{
    vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    int diff=helper(nums,0,nums.size()-1,dp);
    if(diff>=0) return true;
    return false;
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
   cout<<predictTheWinner(nums);
    return 0;
}