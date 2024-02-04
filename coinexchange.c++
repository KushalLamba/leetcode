#include <iostream>
#include <climits>
using namespace std;
// -------------first usoing dp without memorization only recursion----------
// int coinChange(int *coins, int amount, int n) {
//     if (amount == 0) {
//         return 0;
//     }
//     if (amount < 0) {
//         return -1;
//     }
//     int mincount = INT_MAX;
//     for (int i = 0; i < n; i++) {
//         int count = coinChange(coins, amount - coins[i], n);
//         if (count != -1) {
//             mincount = min(count + 1, mincount);
//         }
//     }
//     if (mincount == INT_MAX) {
//         return -1;
//     }
//     return mincount;
// }

/*-----------------USING RECURSION + MEMORIZATION---------------------*/

// int coinChange(int*coins,int amount,int n,int *dp)
// {
//     if(amount==0)
//     {
//         return 0;
//     }
//     if(amount<0)
//     {
//         return -1;
//     }
//     if(dp[amount]!=-1)
//     {
//         return dp[amount];
//     }
//     int mincount=INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//         int count=coinChange(coins,amount-coins[i],n,dp);
//         if(count!=-1)
//         {
//            mincount=min(mincount,count+1);
//         }
//     }
//     if(mincount==INT_MAX)
//     {
//         return -1;
//     }
//     dp[amount]=mincount;
//     return dp[amount];

// }
/* ----------------------Tabular foam----------------------------*/
// int coinChange(int *coins,int amount,int n,int *dp)
// {
//     dp[0]=0;
//     for(int i=1;i<=amount;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
//             dp[i]=min(dp[i],1+dp[i-coins[j]]);
//         }
//     }
//     if(dp[amount]==INT_MAX)
//     {
//         return -1;
//     }
//     return dp[amount];
// }
// space optimization is not possible because it  cannot depend on  complete
// array of coins 
// int main()
// {
//     cout << "Enter Number Of Elements: " << endl;
//     int n;
//     cin >> n;
//     cout << "Enter Elements: " << endl;
//     int *coins = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> coins[i];
//     }
//     cout << "Enter Amount: " << endl;
//     int amount;
//     cin >> amount;
//     cout << coinChange(coins, amount, n);
//     delete[] coins;
// }
