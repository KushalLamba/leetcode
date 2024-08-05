#include<bits/stdc++.h>
using namespace std;
//top to bottom
// int minDistance(string s1,string s2,vector<vector<int>>& dp,int x=0,int y=0)
// {
//     if(y==s2.length()) return s1.length()-x;           //delete 
//     if(x==s1.length()) return s2.length()-y;  ///insert
//     if(dp[x][y]!=-1) return dp[x][y];
//     if(s1[x]==s2[y])
//     {
//         dp[x][y]=minDistance(s1,s2,dp,x+1,y+1);
//     }
//     else
//     {
//         dp[x][y]=1+min(minDistance(s1,s2,dp,x+1,y),min(minDistance(s1,s2,dp,x,y+1),minDistance(s1,s2,dp,x+1,y+1)));
//     } 
//     return dp[x][y];
// }
// bottom to up
// int minDistance(string s1,string s2)
// {
//     int m=s1.length();
//     int n=s2.length();
//     vector<vector<int>> dp(m+1,vector<int>(n+1));
//     for(int i=0;i<=m;i++)
//     {
//         for(int j=0;j<=n;j++)
//         {
//             if(i==0 || j==0)
//             {
//                 dp[i][j]=i+j;
//             }
//             else if( s1[i-1]==s2[j-1])
//             {
//                 dp[i][j]=dp[i-1][j-1];
//             }
//             else
//             {
//                 dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
//             }
//         }
//     }
//     return dp[m][n];
// }
// int main()
// {
//     string s1,s2;
//     cin>>s1>>s2;
//     vector<vector<int>> dp(s1.length(),vector<int>(s2.length(),-1));
//     cout<<minDistance(s1,s2,dp);
//     return 0;
// }