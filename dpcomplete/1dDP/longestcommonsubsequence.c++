#include <bits/stdc++.h>
using namespace std;
// top to down approch
// int longestCommonSubsequence(string s1, string s2, int x, int y)
// {
//     if (s1.length() == x || s2.length() == y)
//         return 0;
//     if (s1[x] == s2[y]) return 1+longestCommonSubsequence(s1,s2,x+1,y+1);
//     else
//     {
//         return max(longestCommonSubsequence(s1,s2,x+1,y),longestCommonSubsequence(s1,s2,x,y+1));
//     }
// }

// Bottom to up approch
// int longestCommonSubsequence(string s1,string s2)
// {
//     int m=s1.length();
//     int n=s2.length();
//     vector<vector<int>> dp(m+1,vector<int>(n+1));
//     for(int i=0;i<=n;i++)
//     {
//         dp[0][i]=0;
//     }
//     for(int i=0;i<=m;i++)
//     {
//         dp[i][0]=0;
//     }
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
//             else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//         }
//     }
//     return dp[m][n];
// }
// int main()
// {
//     string s1, s2;
//     cout << "Enter String S1 and S2: " << endl;
//     cin >> s1 >> s2;
//     cout<<longestCommonSubsequence(s1,s2);
//     return 0;
// }