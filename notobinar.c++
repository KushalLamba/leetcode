#include<iostream>
using namespace std;
string numtobina(int n)
{
    if(n==1) return "1";
    string s=numtobina(n/2);
    s+=to_string(n%2);
    return s;
}
int main()
{
    cout<<"Enter the Element: "<<endl;
    int n;
    cin>>n;
    string s=numtobina(n);
    cout<<s;
}