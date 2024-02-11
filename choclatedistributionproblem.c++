#include <iostream>
#include<climits>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number of Packets: " << endl;
    cin >> n;
    if (n < 5)
    {
        return -1;
    }
    cout << "Enter Number of Students: " << endl;
    int s;
    cin >> s;
    int *arr = new int[n];
    cout << "Each Packet: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = 0;
    int end = s-1;
    sort(arr, arr + n);
    int min = INT_MAX;
    while (end < n)
    {
        if ((arr[end] - arr[start]) < min)
        {
            min = arr[end] - arr[start];
        }
        start++;
        end++;
    }
    cout<<min;
}