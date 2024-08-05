#include<bits/stdc++.h>
using namespace std;
int finder(vector<int>& nums,int pos,int gap,int value)
{
    for(int i=pos;i<nums.size();i++)
    {
        if(abs(nums[i]-value)==gap)
        {
            return i;
        }
    }
    return -1;
}
int numberOfArithmeticSlices(vector<int>& nums,vector<vector<int>>& dp,int pos=0,int count=0,int gap=0,int prev=0)
{
    if(pos>=nums.size())
    {
        if(count>=3) return 1;
        return 0;
    }
    if(prev!=-1 && dp[pos][prev]!=-1) return dp[pos][prev];
    int include=0;
    if(count<=1)
    {
        count++;
        include=numberOfArithmeticSlices(nums,dp,pos+1,count,nums[pos]-nums[prev],pos);
        count--;
    }
    int nextindex=finder(nums,pos,gap,nums[prev]);
    if(nextindex!=-1)
    {
        count++;
        include=numberOfArithmeticSlices(nums,dp,pos+1,count,gap,nextindex);
        count--;
    }
    int exclude=numberOfArithmeticSlices(nums,dp,pos+1,count,gap,prev);
    if(prev!=-1) dp[pos][prev]=include+exclude;
    return include+exclude;
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
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<numberOfArithmeticSlices(nums,dp);
}