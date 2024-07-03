#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{
    int p = 0, n = 0;
    int index = 0;
    while (p < nums.size() && n < nums.size())
    {
        if (nums[p] < 0)
        {
            p++;
        }
        if (nums[n] > 0)
        {
            n++;
        }
        else
        {
            swap(nums[index], nums[p]);
            index+=1;
            swap(nums[index], nums[n]);
            p++;
            index++;
            n++;
        }
    }
    return nums;
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
    vector<int> ans=rearrangeArray(nums);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}