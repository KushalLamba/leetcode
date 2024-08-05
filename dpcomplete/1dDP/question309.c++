#include <bits/stdc++.h>
using namespace std;
// int helper(vector<int> &prices, int pos,
//            int hasStock, vector<vector<int>> &dp)
// {
//     if (pos >= prices.size())
//         return 0;
//     if (dp[pos][hasStock] != -1)
//         return dp[pos][hasStock];
//     if (hasStock == 1)
//     {
//         int buyer = -prices[pos] + helper(prices, pos + 1, 0, dp);
//         int doNothing = helper(prices, pos + 1, 1, dp);
//         return dp[pos][hasStock] = max(buyer, doNothing);
//     }
//     else
//     {
//         int sell = prices[pos] + helper(prices, pos + 2, 1, dp);
//         int doNothing = helper(prices, pos + 1, 0, dp);
//         return dp[pos][hasStock] = max(sell, doNothing);
//     }
// }
// int maxProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n, vector<int>(2, -1));
//     return helper(prices, 0, 1, dp);
// }
int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    vector<int> dp(n,0);
    dp[0]=0;
    dp[1]=max(prices[1]-prices[0],0);
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int todayprofit=prices[i]-prices[j];
            int prevprofit= j>=2 ? dp[j-2] : 0;
            dp[i]=max(dp[i-1],todayprofit+prevprofit);
        }
    }
    return dp[n-1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(prices);
    return 0;
}