#include <bits/stdc++.h>
using namespace std;
int stoneGameII(vector<int> &nums, int pos = 0, int m = 1)
{
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
    cout << stoneGameII(nums);
    return 0;
}