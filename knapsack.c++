#include <iostream>
#include <vector>
using namespace std;
int knapsol(int maxweight, int weight[], int profit[], int index, vector<vector<int>> dp)
{
    if (index < 0)
    {
        return 0;
    }
    if (dp[index][maxweight] != -1)
    {
        return dp[index][maxweight];
    }
    if (maxweight < weight[index])
    {
        dp[index][maxweight] = knapsol(maxweight, weight, profit, index - 1, dp);
        return dp[index][maxweight];
    }
    else
    {
        dp[index][maxweight] = max((profit[index] + knapsol(maxweight - weight[index], weight, profit, index - 1, dp)), knapsol(maxweight, weight, profit, index - 1, dp));
        return dp[index][maxweight];
    }
}
int knapsack(int maxweight, int weight[], int profit[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return knapsol(maxweight, weight, profit, n - 1, dp);
}
int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapsack(W, weight, profit, n);
    return 0;
}