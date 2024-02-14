#include <iostream>
#include<cstring>
using namespace std;
int lengthOfLastWord(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    int start = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ' && i+1<s.length() && s[i+1]!=' ')
        {
            start = i;
        }
    }
    int count = 0;
    for (int i = start+1; i < s.length(); i++)
    {
        if(s[i]!=' ')
        count++;
    }
    return count;
}
int main()
{
    string str;
    getline(cin,str);
    cout<<lengthOfLastWord(str);
}