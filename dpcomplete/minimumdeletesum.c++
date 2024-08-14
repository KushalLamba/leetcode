#include <bits/stdc++.h>
using namespace std;
int helper(string s1, string s2, int i, int j,vector<vector<int>>& dp)
{
    if (i == s1.size() && j == s2.size())
    {
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(i!=s1.size())
    {
        return dp[i][j]=s1[i]+helper(s1,s2,i+1,j,dp);
    }
    if(j!=s2.size()) return dp[i][j]=s2[j]+helper(s1,s2,i,j+1,dp);
    if (s1[i] == s2[j]) return dp[i][j]=helper(s1, s2, i + 1, j + 1,dp);
    else return dp[i][j]=min(s1[i] + helper(s1, s2, i + 1, j,dp), s2[j] + helper(s1, s2, i, j + 1,dp));
}
int minimumDeleteSum(string s1, string s2)
{
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    return helper(s1,s2,0,0,dp);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << minimumDeleteSum(s1, s2);
    return 0;
}