#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int maxlen=0,start=-1;
    vector<int> ans(256,-1);
    for(int i=0;i<s.length();i++)
    {
        if(ans[s[i]]>start)
        {
            start=ans[s[i]];
        }
        ans[s[i]]=i;
        maxlen=max(maxlen,i-start);
    }
    cout<<maxlen;
}