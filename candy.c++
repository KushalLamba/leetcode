#include <iostream>
#include <vector>
using namespace std;
int candy(int *arr,int n)
{
    vector<int> ans(n,1);
    if(n==1)
    {
        return 1;
    }
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1] && ans[i]<=ans[i-1])
        {
            ans[i]=ans[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1] && ans[i]<=ans[i+1])
        {
            ans[i]=ans[i+1]+1;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=ans[i];
    }
    return sum;
}
int main()
{
    cout << "Enter Number Of elements: " << endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << candy(arr, n);
}