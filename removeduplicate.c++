#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int removeDuplicates(int* &arr,int n)
{
    if (n == 1)
    {
        return 1;
    }
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]!=arr[i+1])
        {
            if(i!=count) swap(arr[i],arr[count]);
            count++;
        }
    }
    swap(arr[n-1],arr[count]);
    return count+1;
}
int main()
{
    int n;
    cout << "Enter Number: " << endl;
    cin >> n;
    cout << "Enter Elements: " << endl;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count=removeDuplicates(arr,n);
    for(int i=0;i<count;i++)
    {
        cout<<arr[i]<<" ";
    }
}
