#include<bits/stdc++.h>
using namespace std;
long long maxBalancedSubsequenceSum(vector<int>& nums)
{
    if(nums.size()==0) return 0;
    int n=nums.size();
    map<int,long long> check;
    long long result=INT_MIN;
    for(int i=0;i<n;i++)
    {
        auto it=check.upper_bound(nums[i]-i);
        long long sum=nums[i];
        if(it!=check.begin())
        {
            it--;
            sum+=it->second;
        }
        check[nums[i]-i]=max(check[nums[i]-i],sum);
        it=check.upper_bound(nums[i]-i);
        while(it!=check.end() && it->second<=sum)
        {
            check.erase(it++);
        }
        result=max(result,sum);
    }
    return result;
}
int main()
{
    int n;
    cout<<"Enter N: "<<endl;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
}