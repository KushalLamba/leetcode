#include<bits/stdc++.h>
using namespace std;
int longestSubsequence(vector<int>& nums,int diff)
{
    unordered_map<int,int> mp;
    int maxl=0;
    for(int i=0;i<nums.size();i++)
    {
        if(mp.count(nums[i]-diff)>0)
        {
            mp[nums[i]]=mp[nums[i]-diff];
        }
        mp[nums[i]]++;
        maxl=max(maxl,mp[nums[i]]);
    }
    return maxl;
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
    int diff;
    cin>>diff;
}