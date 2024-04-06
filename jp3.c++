#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    cout<<"Enter the string"<<endl;
    string s;
    cin>>s;
    int ans=0;
    int i=0;
    while(s.length()>0)
    {
        ans=ans+((s[s.length()-1]-96)*pow(20,i));
        cout<<((s[s.length()-1]-96)*pow(20,i))<<endl;
        cout<<ans<<endl;
        s=s.substr(0,s.length()-1);
        i++;
    }
    cout<<ans;
}