#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*-------------------USING RECURSION ONLY----------------------------*/
// int rob(int *arr,int n)
// {
//   if(n==0)
//   {
//     return arr[0];
//   }
//   if(n<0)
//   {
//     return 0;
//   }
//   int include=arr[n]+rob(arr,n-2);
//   int exclude=rob(arr,n-1);
//   return max(include,exclude);
// }

/*----------------RECURSION + MEMORIZATION---------------------------*/

// int rob(int *arr,int n,int *dp)
// {
//    if(n==0)
//    {
//     return arr[0];
//    }
//    if(n<0)
//    {
//     return 0;
//    }
//    if(dp[n]!=-1)
//    {
//     return dp[n];
//    }
//    int include=arr[n]+rob(arr,n-2,dp);
//    int exclude=rob(arr,n-1,dp);
//    dp[n]=max(include,exclude);
//    return dp[n];
// }
/*---------------------WITHOUT RECURSION---------------------*/
// int rob(int *arr, int n)
// {
//     vector<int> dp(n, -1);
//     dp[0] = arr[0];
//     if (n > 1)
//     {
//         dp[1] = arr[1];
//     }
//     for (int i = 2; i < n; i++)
//     {
//         int include = arr[i] + dp[i - 2];
//         int exclude = dp[i - 1];
//         dp[i] = max(include, exclude);
//     }
//     return dp[n - 1];
// }

/*--------------------BEST SOLUTION-----------------*/

// int rob(int *arr,int n) {
//         if (nums.size() == 0) {
//             return 0;
//         } else if (nums.size() == 1) {
//             return nums[0];
//         }
//         int prev1 = nums[0];
//         int prev2 = max(nums[0], nums[1]);
//         for (int i = 2; i < nums.size(); i++) {
//             int curr = max(prev2, prev1 + nums[i]);
//             prev1 = prev2;
//             prev2 = curr;
//         }
//         return prev2;
//     }

// int main()
// {
//     cout << "Enter Number Of Elements in an Array: " << endl;
//     int n;
//     cin >> n;
//     cout << "Enter Elements OF an Array: " << endl;
//     int *arr = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     // int *dp=new int[n+1];
//     // for(int i=0;i<n+1;i++)
//     // {
//     //     dp[i]=-1;
//     // }
//     cout << rob(arr, n /*,dp*/);
//     delete[] arr;
//     // delete[] dp;
// }