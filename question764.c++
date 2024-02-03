
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* ----------------------first method-----------------------------------*/
// int minCostClimbingStairshelper(vector<int>& cost,int k,vector<int> dp)
// {
//     if(k==0)
//     {
//         return cost[0];
//     }
//     if(k==1)
//     {
//         return cost[1];
//     }
//     if(dp[k]!=-1)
//     {
//         return dp[k];
//     }
//     dp[k]=min(minCostClimbingStairshelper(cost,k-1,dp),minCostClimbingStairshelper(cost,k-2,dp))+cost[k];
//     return dp[k];
// }
// int minCostClimbingStairs(vector<int> &cost)
// {
//     int n=cost.size();
//     vector<int> dp(n+1,-1);

//     return min(minCostClimbingStairshelper(cost,n-1,dp),minCostClimbingStairshelper(cost,n-2,dp));
// }
/*-------------------------2nd method -------------------------*/
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n);
//         dp[0] = cost[0];
//         dp[1] = cost[1];
//         for (int i = 2; i < n; i++) {
//             dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//         }
//         return min(dp[n - 1], dp[n - 2]);
//     }
// };
// int main()
// {
//     int n;
//     cout<<"Enter Element of an Array: "<<endl;
//     cin>>n;
//     cout<<"Enter Number Of Elements in an Array: "<<endl;
//     vector<int> cost(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>cost[i];
//     }
//     cout<<minCostClimbingStairs(cost);
// }