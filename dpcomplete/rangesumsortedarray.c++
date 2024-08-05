#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long rangeSum(vector<int> &nums,int left, int right)
{
    vector<int> ans;
    long long sum = 0;
    for(int i=0;i<nums.size();i++)
    {
        ans.push_back(nums[i]);
        int sum=nums[i];
        for(int j=i+1;j<nums.size();j++)
        {
            sum+=nums[j];
            ans.push_back(sum);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = left - 1; i <= right - 1; i++)
    {
        sum += (ans[i]) % mod;
    }
    return (sum) % mod;
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
    int left,right;
    cin>>left>>right;
    cout<<rangeSum(nums,left,right);
    return 0;
}