#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
    cout << "Enter: " << endl;
    int n;
    cin >> n;
    cout << "Enter Elements: " << endl;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << "Enter closing value: " << endl;
    int target;
    cin >> target;
    int minclose = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int first = i + 1;
        int last = n - 1;
        while (first < last)
        {
            int sum = arr[first] + arr[last] + arr[i];
            if(minclose==INT_MAX)
            {
                 minclose=sum;

            }
            else if (abs(minclose - target) > abs(sum - target))
            {
                minclose = sum;
            }
            if (sum < target)
            {
                first++;
            }
            else
            {
                last--;
            }
        }
    }
    cout<<minclose;
    return 0;
}