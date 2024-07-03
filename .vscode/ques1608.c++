#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int specialArray(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for(int i=1;i<nums[nums.size()-1];i++)
    {
        int count=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]>=i) count++;
        }
        if(count==i) return i;
    }
    return -1;
}
int main()
{
    cout << "Enter Number Of Elements: " << endl;
    int n;
    cin >> n;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    cout << specialArray(ans);
}