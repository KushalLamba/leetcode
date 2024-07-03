#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> powerset(vector<int>& nums)
{
    int n=1<<nums.size();
    vector<vector<int>> ans(n);
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<nums.size();j++)
        {
            if((i&(1<<j))!=0) ans[i].push_back(nums[j]);
        }
    }
    return ans;
}
int main()
{
    cout<<"Enter Number Of Elements: "<<endl;
    int n;
    cin>>n;
    vector<int> nums(n,0);
    cout<<"Enter Elements :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<vector<int>> ans=powerset(nums);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}