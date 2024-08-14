#include <bits/stdc++.h>
using namespace std;
int helper(int l, int r,vector<int> &nums, vector<vector<int>> &dp)
{
    if(r-l<2) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int mincost=INT_MAX;
    for(int idx=l+1;idx<=r-1;idx++)
    {
        int result=nums[r]-nums[l]+helper(l,idx,nums,dp)+helper(idx,r,nums,dp);
        mincost=min(result,mincost);
    }
    return dp[l][r]=mincost;
}
int minCost(int n, vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    nums.insert(nums.begin(),0);
    nums.push_back(n);
    int v=nums.size();
    vector<vector<int>> dp(v+1,vector<int>(v+1,-1));
    return helper(0,nums.size()-1,nums,dp);
}
int main()
{
    int x;
    cin>>x;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << minCost(x, nums);
}
