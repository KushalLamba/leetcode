#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& arr,int target)
{
    vector<int> ans;
    int n=arr.size();
    if(n==0)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==target)
        {
            end=mid;
        }
        else if(arr[mid]>target)
        {
            end=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    ans.push_back(start);
    start=0;
    end=n-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==target)
        {
            start=mid;
        }
        else if(arr[mid]>target)
        {
            end=mid-1;
        }
        else
        {
            start=mid;
        }
    }
    ans.push_back(start);
    return ans;
}
int main()
{
    cout << "Enter Number of elements: " << endl;
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter Target: "<<endl;
    int target;
    cin>>target;
    vector<int>ans1=searchRange(arr,target);
    for(int i=0;i<ans1.size();i++)
    {
        cout<<ans1[i];
    }
}