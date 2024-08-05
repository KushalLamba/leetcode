#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums,vector<bool>& visited,int op)
{
    int maxscore=0;
    for(int i=0;i<nums.size();i++)
    {
        if(visited[i]) continue;
        for(int j=i+1;j<nums.size();j++)
        {
            if(visited[j]) continue;
            visited[i]=true;
            visited[j]=true;
            int score=op*__gcd(nums[i],nums[j]);
            int rems=helper(nums,visited,op+1);
            visited[i]=false;
            visited[j]=false;
            maxscore=max(maxscore,score+rems);
        }
    }
    return maxscore;
}
int maxScore(vector<int>& nums)
{
    int n=nums.size();
    vector<bool> visited(n,false);
    return helper(nums,visited,1);
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<maxScore(nums);
}