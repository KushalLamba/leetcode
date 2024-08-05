#include <bits/stdc++.h>
using namespace std;
int maxSatisfaction(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxsum = 0;
    sort(nums.begin(), nums.end());
    for (int i = n - 1; i >= 0; i--)
    {
        int k = 1;
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += k * nums[j];
        }
        maxsum = max(sum, maxsum);
    }
    return maxsum;
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
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << maxSatisfaction(nums);
}