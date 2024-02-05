#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        int sum = -arr[i];
        int first = i + 1;
        int last = n - 1;
        while (first < last)
        {
            if (arr[first] + arr[last] == sum)
            {
                cout << -sum << " " << arr[first] << " " << arr[last] << endl;
                break;
            }
            else if (arr[first] + arr[last] < sum)
            {
                first++;
            }
            else
            {
                last--;
            }
        }
    }
}