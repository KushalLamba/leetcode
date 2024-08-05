#include<bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums)
{
    if(nums.size()==0) return ;
    sort(nums.begin(),nums.end());
    vector<int> dp(nums.size(),1);
    vector<int> pivot(nums.size(),-1);
    int maxval=0;
    int chooseindex=-1;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i;j<i;j++)
        {
            if(nums[i]%nums[j]==0)
            {
                dp[i]=max(dp[i],dp[j]+1);
                pivot[i]=j;
            }
            if(maxval<dp[i])
            {
                chooseindex=i;
                maxval=dp[i];
            }
        }
    }
    vector<int> result;
    while(chooseindex!=-1)
    {
        result.push_back(nums[chooseindex]);
        chooseindex=pivot[chooseindex];   
    }
    return result;
}
int main()
{
    cout<<"Enter Number Of Elements: "<<endl;
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

}