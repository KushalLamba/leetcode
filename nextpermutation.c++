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
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            index=i;
            cout<<index<<endl;
            break;
        }
    }
    if(index==-1)
    {
        sort(arr,arr+n);
    }
    else{
    for(int i=n-1;i>index;i--)
    {
        if(arr[i]>arr[index])
        {
            cout<<arr[i]<<endl;
            swap(arr[i],arr[index]);
            sort(arr+index+1,arr+n);
        }
    }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}