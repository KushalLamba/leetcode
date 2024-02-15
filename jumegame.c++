#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int helper(vector<int> &nums, int i = 0)
{
    if (i >= nums.size() - 1)
    {
        return 0;
    }
    if (nums[i] == 0)
    {
        return INT_MAX;
    }
    int max = 0;
    for (int j = 1; j <= nums[i]; j++)
    {
        cout<<i+j<<endl;
        if (i + j < nums.size())
        {
            if (j == 1)
            {
                max = i + j;
            }
            else
            {
                if (nums[max] < nums[i + j] || i + j == nums.size() - 1)
                {
                    max = i + j;
                }
            }
        }
    }
    return 1 + helper(nums, i + max);
}
int main()
{
    cout << "Enter Number Of elements: " << endl;
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    cout << "Enter Vector: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = helper(nums);
    if (ans == INT_MAX)
    {
        cout << "Answer Is Not Possible" << endl;
    }
    else
    {
        cout << ans;
    }
}