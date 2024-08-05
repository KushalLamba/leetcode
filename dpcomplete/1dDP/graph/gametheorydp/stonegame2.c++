#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums,int pos,int m,int person,vector<vector<vector<int>>>& dp)
{
    int n=nums.size();
    if(pos>=n) return 0;
    if(dp[pos][m][person]!=-1) return dp[pos][m][person];
    int stone=0;
    int result= (person==1) ? 0 : INT_MAX;
    for(int x=1;x<=min(n-pos,2*m);x++)
    {
        if(person==1)
        {
            stone+=nums[pos+x-1];
            result=max(result,stone+helper(nums,pos+x,max(m,x),0,dp));
        }
        else
        {
            result=min(result,helper(nums,pos+x,max(m,x),1,dp));
        }
    }
    return dp[pos][m][person]=result;
}
int stoneGameII(vector<int>& nums)
{
    int n=nums.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n,vector<int>(2,-1)));
    return helper(nums,0,1,1,dp);
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
    cout<<stoneGameII(nums);
}