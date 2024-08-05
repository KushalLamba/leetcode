#include<bits/stdc++.h>
using namespace std;
bool palidrome(string s)
{
    int i=0,j=s.size()-1;
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int countsubstring(string s,int start,int end)
{  
    int start=0;
    int count=0;
    int i=0,j=0;
    while(i<s.size() && j<s.size())
    {
    }
}
int main()
{
    string s;
    cout<<"Enter The String: "<<endl;
    cin>>s;
    cout<<countsubstring(s,0,s.size()-1);
}