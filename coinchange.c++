#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int coinChange(int *coins, int amount, int n)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX;
    }
    int mincount = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int count = coinChange(coins, amount - coins[i], n);
        if(count!=INT_MAX){
        if (mincount > count)
        {
            mincount = min(count+1,mincount);
        }
        }
    }
    return mincount;
}
int main()
{
    int n;
    cout << "Enter Elements Of Array: " << endl;
    cin >> n;
    cout << "Enter Elements of an array: " << endl;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Amount: " << endl;
    int amount;
    cin >> amount;
    cout << coinChange(arr, amount, n);
}