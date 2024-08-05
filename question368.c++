#include <bits/stdc++.h>
using namespace std;
// void helper(vector<int>& nums,vector<int>& temp,vector<int>& result,int index,int prev)
// {
//     if(index==nums.size())
//     {
//         if(temp.size()>result.size()) result=temp;
//         return;
//     }
//     if(prev==-1 || nums[index]%nums[prev]==0)
//     {
//         temp.push_back(nums[index]);
//         helper(nums,temp,result,index+1,index);
//         temp.pop_back();
//     }
//     helper(nums,temp,result,index+1,prev);
// }
// vector<int> largestDivisibleSubset(vector<int> &nums)
// {
//     int maxl=0;
//     int choosenindex=0;
//     vector<int> dp(nums.size(), 1);
//     vector<int> pre(nums.size(), -1);
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (nums[i] % nums[j] == 0)
//             {
//                 if (dp[i] < dp[j] + 1)
//                 {
//                     dp[i] = dp[j] + 1;
//                     pre[i] = j;
//                 }
//                 if(maxl<dp[i])
//                 {
//                     maxl=dp[i];
//                     choosenindex=i;
//                 }
//             }
//         }
//     }
//     vector<int> ans;
//     while(choosenindex!=-1)
//     {
//         ans.push_back(nums[choosenindex]);
//         choosenindex=pre[choosenindex];
//     }
//     return ans;
// }
// int main()
// {
//     cout << "Enter Number Of Elements: " << endl;
//     int n;
//     cin >> n;
//     vector<int> nums(n, 0);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }
//     sort(nums.begin(), nums.end());
//     vector<int> result;
//     vector<int> temp;
//     helper(nums,temp,result,0,-1);
//     vector<int> result = largestDivisibleSubset(nums);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << " ";
//     }
// }