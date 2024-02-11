#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.first>b.first;
}
int main()
{
    cout << "Enter No. of Workers: " << endl;
    int n;
    cin >> n;
    cout << "Enter profit: " << endl;
    int *profit = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>profit[i];
    }
    cout << "Enter ID: " << endl;
    int *id = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> id[i];
    }
    int *deadline = new int[n];
    cout << "Enter Deadline: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> deadline[i];
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++)
    {
        pair<int,int> p=make_pair(profit[i],i);
        ans.push_back(p);
    }
    sort(ans.begin(),ans.end(),cmp);
    vector<int> arr(n,-1);
    for(int i=0;i<n;i++)
    {
        if(arr[])
    }
}