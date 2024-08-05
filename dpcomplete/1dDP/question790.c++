#include<bits/stdc++.h>
using namespace std;
bool valid(string s)
{
   
}
int minFlipMonoIncr(string s,int pos,int prev)
{
    if(pos==s.length()) return 0;
    int flip=INT_MAX;
    int notflip=INT_MAX;
    if(s[pos]==0)
    {
        if(prev==1)
        {
            flip=1+minFlipMonoIncr(s,pos+1,1);
        }
        else
        {
            flip=minFlipMonoIncr(s,pos+1,1);
            notflip=minFlipMonoIncr(s,pos+1,0);
        }
    }
    else
    {
        if(prev==0)
        {
            flip=1+minFlipMonoIncr(s,pos+1,0); 
        }
        else
        {
            flip=minFlipMonoIncr(s,pos+1,0);
            notflip=minFlipMonoIncr(s,pos+1,1);
        }
    }
    return min(flip,notflip);
}
int main()
{
    string s;
    cin>>s;
    cout<<minFlipMonoIncr(s,0,0);
    return 0;
}