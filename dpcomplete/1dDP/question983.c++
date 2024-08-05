#include<bits/stdc++.h>
using namespace std;
int index(vector<int>& days,int pos,int value)
{
    while(pos<days.size() && days[pos]<value) pos++;
    return pos;
}
int mincostTickets(vector<int>& days,vector<int>& costs,int pos,vector<int>& dp)
{
    if(pos==days.size()) return 0;
    if(dp[pos]!=-1) return dp[pos];
    int cost1=costs[0]+mincostTickets(days,costs,pos+1,dp);
    int idx=index(days,pos,days[pos]+7);
    int cost2=costs[1]+mincostTickets(days,costs,idx,dp);
    idx=index(days,pos,days[pos]+30);
    int cost3=costs[2]+mincostTickets(days,costs,idx,dp);
    return dp[pos]=min(cost1,min(cost2,cost3));
}
int main()
{
    int n;
    cin>>n;
    vector<int> days(n);
    vector<int> costs(3);
    for(int i=0;i<n;i++)
    {
        cin>>days[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>costs[i];
    }
    vector<int> dp(n,-1);
    cout<<mincostTickets(days,costs,0,dp);
}