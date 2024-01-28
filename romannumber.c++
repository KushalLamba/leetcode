#include<iostream>
using namespace std;
int main()
{
    string s[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string s1[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C","CX","CXX","CXXX","CXL"};
    int n;
    cout<<"Enter The Number: "<<endl;
    cin>>n;
    int x=n/10;
    int y=n%10;
    cout<<s1[x]+s[y];
}