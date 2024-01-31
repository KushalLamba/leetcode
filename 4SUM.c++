#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter Number Of Elements: " << endl;
    int n;
    cin >> n;
    int nums[n];
    cout << "Enter Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    cout << "Enter Target: " << endl;
    int target;
    cin >> target;
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i+1; j < n - 2; j++)
        {
            if (j > i && nums[j] == nums[j - 1])
            {
                continue;
            }
            int sum = nums[i] + nums[j];
            int first = j + 1;
            int last = n - 1;
            while (first < last)
            {
                if (nums[first] + nums[last] + sum == target)
                {
                    cout << nums[i] << " " << nums[j] << " " << nums[first] << " " << nums[last] << endl;
                    break;
                }
                else if (nums[first] + nums[last] + sum < target)
                {
                    first++;
                }
                else
                {
                    last--;
                }
            }
        }
    }
}