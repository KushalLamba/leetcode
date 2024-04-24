#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int maxSubarrayLength(vector<int> &nums, int k)
{
    unordered_map<int, int> counter;
    int maxcount = 0;
    int start = 0;
    int end = 0;
    while (end < nums.size())
    {
        counter[nums[end]]++;
        while (counter[nums[end]] > k)
        {
            counter[nums[start]]--;
            start++;
        }
        int count = end - start + 1;
        maxcount = max(maxcount, count);
        end++;
    }
    return maxcount;
}
int main()
{
    cout << "Enter size of array: " << endl;
    int n;
    cin >> n;
    vector<int> ans(n, 0);
    cout << "Enter Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    cout << "Enter value of k" << endl;
    int k;
    cin >> k;
    cout << maxSubarrayLength(ans, k);
    return 0;
}