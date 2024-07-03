#include<bits/stdc++.h>
using namespace std;
int beautifulSubsets1(vector<int> nums,int k,int i,unordered_map<int,int> check)
{
    if(i==nums.size())
    {
        if(check.size()==0) return 0;
        return 1;
    }
    int include=0,exclude=0;
    int element1=nums[i]-k;
    int element2=nums[i]+k;
    if(check.size()==0 || (check.count(element1)==0 && check.count(element2)==0))
    {
        check[nums[i]]++;
        include=beautifulSubsets1(nums,k,i+1,check);
        check[nums[i]]--;
        if(check[nums[i]]==0) check.erase(nums[i]);
    }
    exclude=beautifulSubsets1(nums,k,i+1,check);
    return include+exclude;
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
    unordered_map<int,int> check;
    cout << beautifulSubsets1(nums, k,0,check);
    return 0;
}