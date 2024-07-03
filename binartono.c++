#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n=0;
int bintono(string s)
{
    if(s.size()==0) return 0;
    n=bintono(s.substr(1));
    if(s[0]=='1') n+=pow(2,s.size()-1);
    return n;
}
int main()
{
    cout<<"Enter The string: "<<endl;
    string s;
    cin>>s;
    int n=bintono(s);
    cout<<n;
}