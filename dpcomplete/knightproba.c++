#include <bits/stdc++.h>
using namespace std;
double helper(int n, int k, int row, int col,unordered_map<string,double>& mp)
{
    if (row < 0 || row >= n || col < 0 || col >= n)
        return 0;
    string key=to_string(row)+"_"+to_string(col)+"_"+to_string(k);
    if(mp.find(key)!=mp.end()) return mp[key];
    if (k == 0)
        return 1;
    vector<pair<int,int>> directions={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    double ans=0;
    for(auto &dir:directions)
    {
        ans+=(double)helper(n,k-1,row+dir.first,col+dir.second,mp);
    }
    return mp[key]=(double)(ans) / (8.0);
}
double knightProbability(int n,int k,int row,int col)
{
    unordered_map<string,double> mp;
    return helper(n,k,row,col,mp);
}
int main()
{
    int n;
    cin >> n;
    int k, row, col;
    cin >> k >> row >> col;
    cout << knightProbability(n, k, row, col);
    return 0;
}