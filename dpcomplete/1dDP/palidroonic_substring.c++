#include<bits/stdc++.h>
using namespace std;
// int countSubstrings(string s)
// {
//     int count=0;
//     vector<vector<bool>> dp(s.size()+1,vector<bool>(s.size()+1,false));
//     for(int l=1;l<=s.length();l++)
//     {
//         for(int i=0;i+l-1<=s.length();i++)
//         {
//             int j=i+l-i;
//             if(i==j) dp[i][j]=true;
//             else if(i+1==j && s[i]==s[j]) dp[i][j]=true;
//             else
//             {
//                 if(s[i]==s[j] && dp[i+1][j-1])
//                 {
//                     dp[i][j]=true;
//                 }
//             }
//             if(dp[i][j]) count++;
//         }
//     }
//     return count;
// }
void check(string s,int i,int j,int& count)
{
    while(i>=0 && j<s.length() && s[i]==s[j])
    {
        count++;
        i--;
        j++;
    }
    return ;
}
int countSubstrings(string s)
{
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        check(s,i,i,count);
        check(s,i,i+1,count);
    }
    return count;
}
int main()
{
    string s;
    cin>>s;
    cout<<countSubstrings(s);
    return 0;
}