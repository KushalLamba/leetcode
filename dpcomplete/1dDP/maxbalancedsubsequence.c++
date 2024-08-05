#include <bits/stdc++.h>
using namespace std;
long long helper(vector<int> &nums, int pos, int prev)
{
    if (pos == nums.size())
    {
        return INT_MIN;
    }

    long long take = INT_MIN;
    long long skip = INT_MIN;

    if (prev == -1 || (nums[pos] - pos) >= (nums[prev] - prev))
    {
        take = nums[pos] + helper(nums, pos + 1, pos);
    }
    skip = helper(nums, pos + 1, prev);
    return max(skip, take);
}
int main()
{
    cout << "Enter Number of Elements: " << endl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << helper(nums, 0, -1);
}