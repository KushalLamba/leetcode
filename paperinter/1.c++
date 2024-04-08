#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int maxpairs(vector<int> a,vector<int> b)
{
    int count=0;
    int i=0,j=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]>b[j])
        {
            i++;
            j++;
            count++;
        }
        else{
            i++;
        }
    }
    return count;
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> a(m);
    vector<int> b(n);
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout<<maxpairs(a,b);
    return 0;
}