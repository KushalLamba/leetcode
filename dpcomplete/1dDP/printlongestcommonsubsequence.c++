#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> longestCommonSubsequence(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp;
}
string printlongestCommonSubsequence(string s1, string s2)
{
    vector<vector<int>> dp = longestCommonSubsequence(s1, s2);
    int i = s1.length(), j = s2.length();
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j]==dp[i][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << printlongestCommonSubsequence(s1, s2);
    return 0;
}