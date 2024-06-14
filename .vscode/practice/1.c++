#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int total(vector<int> arr,int low,int mid,int high)
{
    int tempsum=0;
    int leftcrosssum=0;
    int rightcrosssum=0;
    for(int i=mid;i>=0;i--)
    {
        tempsum+=arr[i];
        leftcrosssum=max(leftcrosssum,tempsum);
    }
    tempsum=0;
    for(int i=mid+1;i<=high;i++)
    {
        tempsum+=arr[i];
        rightcrosssum=max(rightcrosssum,tempsum);
    }
    return leftcrosssum+rightcrosssum;
}
int maxsubarray(vector<int> arr,int low,int high)
{
    int sum=0;
    int maxsum=0;
    if(high==low) return arr[low];
    int mid=low+(high-low)/2;
    int leftsum=maxsubarray(arr,low,mid);
    int rightsum=maxsubarray(arr,mid+1,high);
    int crosssum=total(arr,low,mid,high);
    sum=max(crosssum,max(leftsum,rightsum));
    if(sum>maxsum)
    {
        maxsum=sum;
    }
    return maxsum;
}
int main()
{
    cout<<"enter number of element: "<<endl;
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxsubarray(arr,0,n-1);
}