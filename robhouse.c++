#include <iostream>
using namespace std;
// int rob(int *arr,int n)
// {
//     if(n<0)
//     {
//         return 0;
//     }
//     if(n==0)
//    {
//      return arr[0ro];
//     }
//     return max(rob(arr,n-1),arr[n]+rob(arr,n-2));
// }
int rob(int *arr, int n, int *dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = max(rob(arr, n - 1, dp), arr[n] + rob(arr, n - 2, dp));
    return dp[n];
}
int main()
{
    int n;
    cout << "Enter Number Of Elements: " << endl;
    cin >> n;
    cout << "Enter Elements Of Array: " << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *dp = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = -1;
    }
    // cout<<rob(arr,n-1,dp);
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int sum = 0;
        while (j < n)
        {
            sum += arr[j];
            j += 2;
        }
    }
}