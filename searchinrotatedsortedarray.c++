#include <iostream>
using namespace std;
int main()
{
    cout << "Enter Number Of elements: " << endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Target: " << endl;
    int target;
    cin >> target;
    int start = 0;
    int end = n - 1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==target)
        {
            cout<<mid;
            break;
        }
        if(arr[mid]>arr[start])
        {
           if(arr[start]>target)
           {
            start=mid+1;
           }
           else end=mid-1;
        }
        else 
        {
            if(arr[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
    }
}