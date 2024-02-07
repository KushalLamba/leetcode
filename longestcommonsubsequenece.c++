#include <iostream>
#include <vector>
using namespace std;
// int lonsubseq(string str1, string str2, vector<vector<int>> dp, int i = 0, int j = 0)
// {
//     if (i == str1.length() || j == str2.length())
//     {
//         return 0;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int ans = 0;
//     if (str1[i] == str2[j])
//     {
//         ans = 1 + lonsubseq(str1, str2, dp, i + 1, j + 1);
//     }
//     else
//     {
//         ans = max(lonsubseq(str1, str2, dp, i + 1, j), lonsubseq(str1, str2, dp, i, j + 1));
//     }
//     dp[i][j] = ans;
//     return dp[i][j];
// }
// int longestCommonSubsequence(string str1, string str2)
// {
//     vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
//     for (int i = str1.length() - 1; i >= 0; i--)
//     {
//         for (int j = str2.length() - 1; j >= 0; j--)
//         {
//             int ans = 0;
//             if (str1[i] == str2[j])
//             {
//                 ans = 1 + dp[i+1][j+1];
//             }
//             else ans=max(dp[i][j+1],dp[i+1][j]);
//             dp[i][j]=ans;
//         }
//     }
//     return dp[0][0];
// }
int longestCommonSubsequence(string s1, string s2)
{
    vector<int> curr(s2.length() + 1, 0);
    vector<int> next(s2.length() + 1, 0);
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (s1[i] == s2[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                ans = max(next[j], curr[j+1]);
            }
            curr[j]=ans;
        }
        next=curr;
    }
    return next[0];
}
int main()
{
    cout << "Enter String 1: " << endl;
    string str1;
    cin >> str1;
    cout << "Enter String 2: " << endl;
    string str2;
    cin >> str2;
    vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), -1));
    cout << longestCommonSubsequence(str1, str2);
    dp.clear();
}