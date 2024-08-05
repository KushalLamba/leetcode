#include<bits/stdc++.h>
using namespace std;
// Recurion + Memorization approch
// int lengthLIS(vector<int>& nums,int pos,int prev,vector<vector<int>> dp)
// {
//     if(nums.size()<=pos) return 0;
//     if(prev!=-1 && dp[pos][prev]!=-1) return dp[pos][prev];
//     int take=0;
//     int skip=0;
//     if(prev==-1 || nums[pos]>nums[prev])
//     {
//         take=1+lengthLIS(nums,pos+1,pos,dp);
//     }
//     skip=lengthLIS(nums,pos+1,prev,dp);
//     return dp[pos][prev]=max(skip,take);
// }
// Dynamic approch
// int lengthLIS(vector<int>& nums)
// {
//     if(nums.size()==0) return 0;
//     vector<int> dp(nums.size(),1);
//     int maxlenght=0;
//     for(int i=0;i<nums.size();i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             if(nums[i]>nums[j])
//             {
//                 dp[i]=max(dp[i],dp[j]+1);
//             }
//         }
//         maxlenght=max(maxlenght,dp[i]);
//     }
//     return maxlenght;
// }
// int main()
// {
//     cout<<"Enter Value of N: "<<endl;
//     int n;
//     cin>>n;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>nums[i];
//     }
//     // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//     cout<<lengthLIS(nums);
// }