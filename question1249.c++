#include <iostream>
using namespace std;
string minRemoveToMakeValid(string s)
{
    int left = 0;
    string str;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            left++;
        }
        else if (s[i] == ')')
        {
            left--;
        }
        if (left < 0)
        {
            left = 0;
        }
        else
        {
            str.push_back(s[i]);
        }
    }
    return str;
}
int main()
{
    cout<<"Enter string: "<<endl;
    string s;
    cin>>s;
    cout<<minRemoveToMakeValid(s);
}