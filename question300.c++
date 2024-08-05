#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(vector<int>& nums)
{
    vector<int> dp(nums.size(),1);
    for(int i=1;i<nums.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i]>nums[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int maxi=0;
    for(int i=0;i<dp.size();i++)
    {
        maxi=max(maxi,dp[i]);
    }
    return maxi;
}
int main()
{
    cout<<"Enter Number Of Elements: "<<endl;
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<longestIncreasingSubsequence(nums);
}