#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums1,vector<int>& nums2,int pos,int prev,map<pair<int,int>,int> mp)
{
    if(pos==nums1.size()) return 0;
    if(mp.find(make_pair(pos,prev))!=mp.end()) return mp[make_pair(pos,prev)];
    int op1=INT_MAX;
    int op2=INT_MAX;
    if(prev<nums1[pos])
    {
        op1=helper(nums1,nums2,pos+1,pos,mp);
    }
    auto it=upper_bound(nums2.begin(),nums2.end(),prev);
    if(it!=nums2.end())
    {
        int j=nums2.begin()-it;
        op2=helper(nums1,nums2,pos+1,nums2[j],mp);
    }
    return mp[make_pair(pos,prev)]=min(op1,op2);
}
int makeArrayIncreasing(vector<int>& arr1,vector<int>& arr2,int pos,int prev,int pos2)
{
   map<pair<int,int>,int> mp;
   sort(arr2.begin(),arr2.end());
   int ans=helper(arr1,arr2,0,INT_MIN,mp);
   return ans==INT_MAX ? -1 : ans;
}
int main()
{
    return 0;
}