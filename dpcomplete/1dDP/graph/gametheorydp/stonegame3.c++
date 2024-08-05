#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums,int pos,vector<int>& dp)
{
    if(pos>=nums.size()) return 0;
    if(dp[pos]!=-1) return dp[pos];
    int result=0;
    result=nums[pos]-helper(nums,pos+1,dp);
    if(pos+1<nums.size()) result=nums[pos]+nums[pos+1]-helper(nums,pos+2,dp);
    if(pos+2<nums.size()) result=nums[pos]+nums[pos+1]+nums[pos+2]-helper(nums,pos+3,dp);
    return dp[pos]=result;
}
string stoneGameIII(vector<int>& stoneValue)
{
    int n=stoneValue.size();
   vector<int> dp(n,-1); 
   int diff=helper(stoneValue,0,dp);
   if(diff>0) return "Alice";
   else if(diff<0) return "Bob";
   else return "Tie";
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
    cout<<stoneGameIII(nums);
    return 0;
}