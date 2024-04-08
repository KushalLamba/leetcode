#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string ans(string s)
{
    string ans;
    vector<int> odd;
    vector<int> even;
    for(int i=0;i<s.size();i++)
    {
        int a=s[i]-48;
        if(a%2==0)
        {
            even.push_back(a);
        }
        else
        {
            odd.push_back(a);
        }
    }
    sort(even.rbegin(),even.rend());
    sort(odd.rbegin(),odd.rend());
    int o=0,e=0;
    for(int i=0;i<s.size();i++)
    {
        int a=s[i]-48;
        int next=0;
        if(i+1<s.size())
        next=s[i+1]-48;
        if(a%2==0 && next%2==0)
        {
              ans+=to_string(48+even[e]);
              e++; 
        }
        else{
            ans+=to_string(48+odd[o]);
            o++;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<ans(s);
    return 0;
}