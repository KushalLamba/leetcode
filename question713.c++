#include <iostream>
#include <vector>
using namespace std;
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int sum = 1;
    vector<vector<int>> ans;
    int start = 0;
    int end = 0;
    while (end < nums.size())
    {
        sum = sum * nums[end]; 
        if (sum < k)
        {
            vector<int> taker;
            for (int p = start; p <= end; p++)
            {
                taker.push_back(nums[p]);
            }
            ans.push_back(taker);
            end++;
        }
        else
        {
            sum = sum / nums[start];
            start++;
        }
    }
    return ans.size();
}
int main()
{
    cout << "Enter Number of Elements: " << endl;
    int n;
    vector<int> value(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    return 0;
}