#include<bits/stdc++.h>
using namespace std;
vector<int> secondno(vector<int>& nums)
{
    int xor2=0;
    for(int i=0;i<nums.size();i++)
    {
        xor2=xor2^nums[i];
    }
    int xor0=0,xor1=0;
    for(int i=0;i<nums.size();i++)
    {
        if(xor2^nums[i]==0) xor0=xor0^nums[i];
        else xor1=xor1^nums[i];
    }
    vector<int> ans;
    ans.push_back(xor0);
    ans.push_back(xor1);
    return ans;
}
int main()
{
    cout<<"enter no :"<<endl;
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int> ans=secondno(nums);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}