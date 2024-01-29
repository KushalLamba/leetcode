/*                                leetcode question no.11                                       */
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int first=0;
    int last=n-1;
    int height=0;
    int weight=0;
    int area=0;
    while(first<=last)
    {
        weight=last-first;
        if(arr[first]<arr[last])
        {
            height=arr[first];
            first++;
        }
        else{
            height=arr[last];
            last--;
        }
        if(area<height*weight)
        {
            area=height*weight;
        }
        
    }
    cout<<area;
}