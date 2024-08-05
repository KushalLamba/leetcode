#include<bits/stdc++.h>
using namespace std;
bool predecessor(string s1,string s2)
{
    if(s1.size()+1!=s2.size()) return false;
    int i=0,j=0;
    while(i<s1.size() && j<s2.size())
    {
        if(s1[i]==s2[j]) i++;
        j++;
    }
    return i==s1.size();
}
int longestStrChain(vector<string>& words,int pos,int prev,vector<vector<int>>& dp)
{
    if(words.size()==pos)
    {
        return 0;
    }
    if(prev!=-1 && dp[pos][prev]!=-1) return dp[pos][prev];
    int take=0;
    int skip=0;
    if(prev==-1 || predecessor(words[prev],words[pos]))
    {
        take=1+longestStrChain(words,pos+1,pos,dp);
    }
    skip=longestStrChain(words,pos+1,prev,dp);
    return dp[pos][prev]=max(take,skip);
}
static bool cmp(string s1,string s2)
{
    return s1.length()<s2.length();
}
int main()
{
    cout<<"Enter Number Of Words: "<<endl;
    int n;
    cin>>n;
    vector<string> words(n,"");
    for(int i=0;i<n;i++)
    {
        cin>>words[i];
    }
    sort(words.begin(),words.end(),cmp);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<longestStrChain(words,0,-1,dp);
}