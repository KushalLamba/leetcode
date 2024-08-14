#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int maxv = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[i] == dp[j] + 1)
                    count[i]++;
                else
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (maxv < dp[i])
        {
            maxv = dp[i];
            maxi = i;
        }
    }
    return count[maxi];
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
    cout << findNumberOfLIS(nums);
    return 0;
}