#include<bits/stdc++.h>
using namespace std;
int singlenumberI(vector<int>& nums)
{
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum=sum^nums[i];
    }
    return sum;
}
int main()
{
    cout<<"Enter Number Of Elements: "<<endl;
    int n;
    cin>>n;
    vector<int> nums(n,0);
    cout<<"Enter: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<singlenumberI(nums);
    return 0;
}