#include <bits/stdc++.h>
using namespace std;
bool uniquechar(string s1, string s2)
{
    vector<int> arr(26, 0);
    for (int i = 0; i < s1.length(); i++)
    {
        int idx = s1[i] - 'a';
        if(arr[idx]>0) return false;
        arr[idx]++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        int idx = s2[i] - 'a';
        if (arr[idx] > 0)
            return false;
        arr[idx]++;
    }
    return true;
}
int maxLength(vector<string> &nums, int pos = 0, string temp = "")
{
    if (pos >= nums.size())
        return temp.length();
    int exclude = 0;
    int include = 0;
    if (!uniquechar(temp,nums[pos]))
    {
        exclude = maxLength(nums, pos + 1, temp);
    }
    else
    {
        exclude = maxLength(nums, pos + 1, temp);
        include = maxLength(nums, pos + 1, temp + nums[pos]);
    }
    return max(include, exclude);
}
int helper(vector<string>& nums)
{
    int maxlen=0;
    for(int i=0;i<nums.size();i++)
    {
        string s;
        for(int j=i;j<nums.size();j++)
        {
            if(uniquechar(s,nums[j]))
            {
                s+=nums[j];
                int k=s.size();
                maxlen=max(maxlen,k);
            }
        }
    }
    return maxlen;
}
int main()
{
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << helper(nums);
}