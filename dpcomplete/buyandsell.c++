#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &nums, int pos, bool buy,map<pair<int,bool>,int>& mp)
{
    if (pos >= nums.size())
        return 0;
    if(mp.find(make_pair(pos,buy))!=mp.end()) return mp[make_pair(pos,buy)];
    int maxprofit = 0;
    if (buy)
    {
        int take = helper(nums, pos + 1, false,mp) - nums[pos];
        int nottake = helper(nums, pos + 1, true,mp);
        maxprofit = max(maxprofit, max(take, nottake));
    }
    else
    {
        int sell = helper(nums, pos + 2, true,mp) + nums[pos];
        int notsell = helper(nums, pos + 1, false,mp);
        maxprofit = max(maxprofit, max(sell, notsell));
    }
    return mp[make_pair(pos,buy)]=maxprofit;
}
int maxProfit(vector<int> &nums)
{
    map<pair<int,bool>,int> mp;
    return helper(nums, 0, true,mp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maxProfit(nums);
    return 0;
}