#include<bits/stdc++.h>
using namespace std;
bool helper(string s,unordered_set<string>& mp,vector<int>& dp,int idx)
{
    if(mp.find(s.substr(idx))!=mp.end()) return true;
    for(int l=1;l<=s.size()-idx;l++)
    {
        string temp=s.substr(idx,l);
        if(mp.find(temp)!=mp.end() && helper(s,mp,dp,idx+l)) return true;
    }
    return false;
}
bool wordBreak(string s,vector<string>& wordDict)
{
    unordered_set<string> mp;
    vector<int> dp(s.size()+1,-1);
    for(int i=0;i<wordDict.size();i++)
    {
        mp.insert(wordDict[i]);
    }
    return helper(s,mp,dp,0);
}
int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> worddict(n);
    for(int i=0;i<n;i++)
    {
        cin>>worddict[i];
    }
    cout<<wordBreak(s,worddict);
    return 0;
}