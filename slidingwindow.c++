/*                         sliding window using deque O(n)                        */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter Number Of Element and Sliding size: "<<endl;
    int n,k;
    cin>>n>>k;
    int arr[n];
    vector<int> ans;
    cout<<"Enter Elements of Array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    deque<int> dq;
    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && arr[dq.back()]<arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    for(int i=k;i<n;i++)
    {
        if(dq.front()==i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}