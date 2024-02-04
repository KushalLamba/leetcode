/*------------------MINIMUM COST TO CUT A STICK--------------------------*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <climits>

int minCost(int *arr, int n, int value)
{
    if (value == 0)
    {
        return arr[0];
    }
    if (value < 0)
    {
        return INT_MAX;
    }
    int mincount = INT_MAX;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        int ans = minCost(arr, n, value - arr[i]);
        if (ans != INT_MAX)
        {
            ans += arr[i];
            mincount = min(mincount, ans);
        }
    }
    if(mincount!=INT_MAX)
    {
        sum+=mincount;
    }
    return sum;
}

int main()
{
    cout << "Enter No. Elements: " << endl;
    int n;
    cin >> n;
    cout << "Enter Elements: " << endl;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int value;
    cout << "Enter Value: " << endl;
    cin >> value;
    cout << minCost(arr, n, value);
}