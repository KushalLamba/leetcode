#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &nums, int pos, int buy, int sell)
{
    if (pos == nums.size())
        return 0;
    if (pos == 0 || (buy == -1 && sell != pos - 1))
        buy = pos;
    int profit = 0;
    int maxprofit = 0;
    int ans = 0;
    if (buy != -1)
    {
        int value = nums[pos] - nums[buy];
        profit = maxProfit(nums, pos + 1, buy, sell);
        if (maxprofit < value)
        {
            maxprofit = value;
            sell = pos;
            buy=-1;
        }
    }
    ans = maxprofit + maxProfit(nums, pos + 1, buy, sell);
    return ans;
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
    cout<<maxProfit(nums,0,-1,-1);
}