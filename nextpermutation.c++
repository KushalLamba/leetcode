#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number Of elements: " << endl;
    ;
    cin >> n;
    cout << "Enter Elements: " << endl;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        sort(arr, arr + n);
    }
    else
    {
        for (int i = n - 1; i >=index + 1; i--)
        {
            if (arr[i] > arr[index])
            {
                swap(arr[i], arr[index]);
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}