#include<bits/stdc++.h>
using namespace std;
int minBitFlips(vector<int>& nums,int k)
{
    vector<int> flipcount(nums.size(),0);
    int flip=0;
    int curr_flip=0;
    for(int i=0;i<nums.size();i++)
    {
        if(i>=k)
        {
            curr_flip-=nums[i-k];
        }
        if((nums[i]+curr_flip)%2==0)
        {
            if(i+k>nums.size()) return -1;
            flipcount[i]++;
            flip++;
            curr_flip++;
        }
    }
    return flip;
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
    cout<<"Enter Value of K:"<<endl;
    int k;
    cin>>k;
}