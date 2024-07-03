#include <iostream>
#include <vector>
using namespace std;
void finder(vector<int> nums, int k, vector<int> ans, int i, int &count)
{
    if (i == nums.size())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = i + 1; j < ans.size(); j++)
            {
                if (abs(ans[i] - ans[j]) == k)
                {
                    return;
                }
            }
        }
        if (!ans.empty())
            count++;
        return;
    }
    ans.push_back(nums[i]);
    finder(nums, k, ans, i + 1, count);
    ans.pop_back();
    finder(nums, k, ans, i + 1, count);
}
int beautifulSubsets(vector<int> nums, int k)
{
    vector<int> ans;
    int count = 0;
    finder(nums, k, ans, 0, count);
    return count;
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
    int k;
    cin >> k;
    cout << beautifulSubsets(nums, k);
    return 0;
}
