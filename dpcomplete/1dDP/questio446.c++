#include <bits/stdc++.h>
using namespace std;
int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;
    unordered_map<int, int> index[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<i;j++)
        {
            int value=nums[i]-nums[j];
            if(index[j].count(value)==0)
            {
                count=0;
            }
            else
            {
                count=index[j][value];
            }
            index[i][value]+=count+1;
            sum+=count;
        }
    }
    return sum;
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
    cout << numberOfArithmeticSlices(nums);
}