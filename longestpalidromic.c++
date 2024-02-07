#include<iostream>
using namespace std;
string answer(string s)
{
    if(s.empty())
    {
        return "";
    }
    if()
    for(int i=0;i<s.length();i++)
    {
        string s=answer(s.substr(1));
    }
}
int main()
{
    string s;
    cout<<"Enter string: "<<endl;
    cin>>s;

}