// #include<bits/stdc++.h>
// using namespace std;
// int longestPalindromeSubseq(string s,int i,int j,vector<vector<int>> dp)
// {
//     if(i>j) return 0;
//     if(i==j) return 1;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(s[i]==s[j])
//     {
//         return dp[i][j]=2+longestPalindromeSubseq(s,i+1,j-1,dp);
//     }
//     else
//     {
//         return max(longestPalindromeSubseq(s,i+1,j,dp),longestPalindromeSubseq(s,i,j-1,dp));
//     }
// }
// int longestPalindromeSubseq(string s)
// {
//     int count=0;
//     vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
//     for(int l=1;l<=s.length();l++)
//     {
//         for(int i=0;i+l-1<s.length();i++)
//         {
//             int j=i=l-1;
//             if(i==j) dp[i][j]=1;
//             if(s[i]==s[j])
//             {
//                 dp[i][j]=2+dp[i+1][j-1];
//             }
//             else{
//                 dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
//             }
//         }
//     }
//     return dp[0][s.length()-1];
// }
// int main()
// {
//     return 0;
// }