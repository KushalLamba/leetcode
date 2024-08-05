#include<bits/stdc++.h>
using namespace std;
// vector<vector<int>> dp(1001,vector<int>(1001,-1));
// bool check(string s,int i,int j)
// {
//     if(i>j)
//     {
//         return true;
//     }
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(s[i]==s[j]) return dp[i][j]=check(s,i+1,j-1);
//     return dp[i][j]=false;
// }
// string longestPalidrome(string s)
// {
//     int maxlen=INT_MIN;
//     int si=-1;
//     for(int i=0;i<s.length();i++)
//     {
//         for(int j=i;j<s.length();j++)
//         {
//             if(check(s,i,j))
//             {
//                 if(j-i+1>maxlen)
//                 {
//                     maxlen=j-i+1;
//                     si=i;
//                 }
//             }
//         }
//     }
//     return s.substr(si,maxlen);
// }
string longestPalindrome(string s)
{
    vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
    int maxlen=INT_MIN;
    int si=-1;
    for(int l=1;l<=s.size();l++)
    {
        for(int i=0;i+l-1<s.length();i++)
        {
            int j=i+l-1;
            if(i==j)
            {
                dp[i][j]=true;
            }
            else if(i+1==j && s[i]==s[j])
            {
                dp[i][j]=true;
            }
            else
            {
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=true;
                }
            }
            if(j-i+1>maxlen)
            {
                maxlen=j-i+1;
                si=i;
            }
        }
    }
    return s.substr(si,maxlen);
}
int main()
{
    string s;
    cin>>s;
    return 0;
}
