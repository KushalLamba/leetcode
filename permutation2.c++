#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ans;
void helper(vector<int> &nums, vector<int> &temp, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
        }
        ans.push_back(temp);
        for (int i = 0; i < nums.size(); i++)
        {
            temp.pop_back();
        }
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(nums[start], nums[i]);
        if (i==end || nums[i+1] != nums[i])
        {
            helper(nums, temp, start + 1, end);
        }
        swap(nums[start], nums[i]);
    }
}
int main()
{
    cout << "Enter Number Of Elements: " << endl;
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> temp;
    helper(nums, temp, 0, n - 1);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}