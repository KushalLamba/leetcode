#include<bits/stdc++.h>
using namespace std;
int maxelement(vector<int>& nums,int pos)
{
    int maxi=INT_MIN;
    for(int i=pos;i<nums.size();i++)
    {
        maxi=max(maxi,nums[i]);
    }
    return maxi;
}
int minDifficulty(vector<int>& nums,int d)
{
    int n=nums.size();
    if(d<n) return -1;
    vector<vector<int>> dp(n,vector<int>(d+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][1]=maxelement(nums,i);
    }
    for(int day=2;day<=2;day++)
    {
        for(int i=0;i<=n-day;i++)
        {
            int maxd=INT_MIN;
            int result=INT_MAX;
            for(int j=i;j<=n-day;j++)
            {
                maxd=max(maxd,nums[i]);
                result=min(result,maxd+dp[j+1][day-1]);
            }
            dp[i][day]=result;
        }
    }
    return dp[0][d];
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<nums.size();i++)
    {
        cin>>nums[i];
    }
    int d;
    cin>>d;

    return 0;
}