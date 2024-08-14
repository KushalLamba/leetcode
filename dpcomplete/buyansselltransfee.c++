#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums,int fee,int pos,bool buy,map<pair<int,bool>,int> mp)
{
    if(pos>=nums.size()) return 0;
    if(mp.find(make_pair(pos,buy))!=mp.end()) return mp[make_pair(pos,buy)];
    if(buy)
    {
        int take=helper(nums,fee,pos+1,false,mp)-nums[pos];
        int nottake=helper(nums,fee,pos+1,true,mp);
        return mp[make_pair(pos,buy)]=max(take,nottake);
    }
    else
    {
        int sell=helper(nums,fee,pos+1,true,mp)+nums[pos]-fee;
        int notsell=helper(nums,fee,pos+1,false,mp);
        return mp[make_pair(pos,buy)]=max(sell,notsell);
    }
}
int maxProfit(vector<int>& nums,int fee)
{
    map<pair<int,bool>,int> mp;
    return helper(nums,fee,0,true,mp);
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
    int fee;
    cin>>fee;
    cout<<maxProfit(nums,fee);
    return 0;
}