#include<bits/stdc++.h>
using namespace std;
// int secondno(vector<int>& nums)
// {
//     int ans=0;
//     for(int i=0;i<32;i++)
//     {
//         int count=0;
//         for(int j=0;j<nums.size();j++)
//         {
//             if((nums[j]&(1<<i))!=0) count++;
//         }
//         if(count%3!=0) ans=ans|1<<i;
//     }
//     return ans;
// }
int secondno(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i=i+3)
    {
        if(nums[i-1]!=nums[i])return nums[i-1];
    }
    return  nums[nums.size()-1];
}
// int secondno(vector<int>& nums)
// {
//     int one=0,two=0;
//     for(int i=0;i<nums.size();i++)
//     {
//         one=(one^nums[i])&(~two);
//         two=(two^nums[i])&(~one);
//     }
//     return one;
// }
int main()
{
    int n;
    cout<<"Enter No. :"<<endl;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<secondno(nums);
}