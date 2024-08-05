#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter Number of Elements: "<<endl;
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        cin>>nums[i][0];
        cin>>nums[i][1];
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++)
    {
        cout<<nums[i][0]<<" "<<nums[i][1]<<"  ";
    }
}