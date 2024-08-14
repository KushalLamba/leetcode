#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> mls={{100,0},{75,25},{50,50},{25,75}};
double helper(int a,int b,map<pair<int,int>,double>& mp)
{
    if(a<=0 && b<=0) return 0.0;
    if(a<=0) return 0.5;
    if(b<=0) return 0;
    if(mp.find(make_pair(a,b))!=mp.end()) return mp[make_pair(a,b)];
    double ans=0;
    for(int i=0;i<4;i++)
    {
        ans+=(double)(0.25*helper(a-mls[i].first,b-mls[i].second,mp));
    }
    return mp[make_pair(a,b)]=ans;
}
double soupServing(int n)
{
    map<pair<int,int>,double> mp;
    return helper(n,n,mp);
}
int main()
{
    int n;
    cin>>n;
    cout<<soupServing(n);
    return 0;
}