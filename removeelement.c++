#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number: "<<endl;
    cin>>n;
    cout<<"Enter Elements: "<<endl;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element that you want to be delete: "<<endl;
    int x;
    cin>>x;
    int change=n-1;
    int i=0;
    while(i<=change)
    {
        if(arr[i]==x)
        {
            swap(arr[change],arr[i]);
            i--;
            change--;
        }
        i++;
    }
    for(int j=0;j<i;j++)
    {
        cout<<arr[j]<<" ";
    }
}