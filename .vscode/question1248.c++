#include <bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int> &nums, int k)
{
    int oddcount=0;
    int ans=0;
    int start=0;
    int i=0;
    while(i<nums.size() && oddcount<k)
    {
        if(nums[i]%2!=0) oddcount++;
        i++;
    }
    if(oddcount==k) ans++;
    while(i<nums.size())
    {
        while(start<nums.size() && oddcount==k && nums[start]%2==0)
        {
            ans++;
            start++;
        }
        if(nums[i]%2!=0)
        {
            start++;
        }
        else ans++;
        i++;
    }
    return ans;
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
    cout << "Enter Value Of K: " << endl;
    int k;
    cin >> k;
}