#include<bits/stdc++.h>
using namespace std;
// Recursion
// long long helper(vector<int>& nums,int pos,bool flag)
// {
//     if(pos==nums.size()) return 0;
//     int skip=helper(nums,pos+1,flag);
//     int value=nums[pos];
//     if(flag==false) value=-value;
//     int take=helper(nums,pos+1,!flag)+value;
//     return max(take,skip);
// }
// long long maximumAlternatingSum(vector<int>& nums)
// {
//     if(nums.size()==0) return 0;
//     return helper(nums,0,true);
// }
// Recursion+ Memorization
// long long helper(vector<int>& nums,vector<vector<int>>& dp,int pos,bool flag)
// {
//     if(pos==nums.size()) return 0;
//     if(dp[pos][flag]!=-1) return dp[pos][flag]; 
//     int skip=helper(nums,dp,pos+1,flag);
//     int value=nums[pos];
//     if(flag==false) value=-value;
//     int take=helper(nums,dp,pos+1,!flag)+value;
//     return dp[pos][flag]=max(take,skip);
// }
// long long maximumAlternatingSum(vector<int>& nums)
// {
//     if(nums.size()==0) return 0;
//     vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
//     return helper(nums,dp,0,true);
// }
// Dynamic Approch
long long maximumAlternatingSum(vector<int>& nums)
{
    if(nums.size()==0) return 0;
    vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,0));
    for(int i=1;i<=nums.size();i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]-nums[i-1]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+nums[i-1]);
    }
    return max(dp[nums.size()][0],dp[nums.size()][1]);
}
int main()
{
    int n;
    cout<<"Enter N: "<<endl;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<maximumAlternatingSum(nums);
}