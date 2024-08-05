#include <bits/stdc++.h>
using namespace std;
// int commonsupersequence(string s1,string s2,int x=0,int y=0)
// {
//     if(s1.length()==x || s2.length()==y)
//     {
//         if(s1.length()==x) return s2.size()-y;
//         if(s2.length()==y) return s1.size()-x;
//     }
//     if(s1[x]!=s2[y])
//     {
//         return 1+min(commonsupersequence(s1,s2,x+1,y),commonsupersequence(s1,s2,x,y+1));
//     }
//     else
//     {
//         return 1+commonsupersequence(s1,s2,x+1,y+1);
//     }
// }
vector<vector<int>> commonsupersequence(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int i = 0; i <= n; i++)
        dp[0][i] = i;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp;
}
string shortestCommonSupersequence(string s1, string s2)
{
    vector<vector<int>> dp = commonsupersequence(s1, s2);
    string ans = "";
    int i = s1.length(), j = s2.length();
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j]<dp[i][j-1])
            {
                ans+=s1[i-1];
                i--;
            }
            else
            {
                ans+=s2[j-1];
                j--;
            }
        }
    }
    while(i>0)
    {
        ans+=s1[i-1];
        i--;
    }
    while(j>0)
    {
        ans+=s2[j-1];
        j--;
    }
    return ans;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout<<shortestCommonSupersequence(s1, s2);
    return 0;
}