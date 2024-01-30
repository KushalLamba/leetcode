#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    if (s.empty())
    {
        return true;
    }
    stack<char> pendingnodes;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            pendingnodes.push(s[i]);
        }
        else
        {
            if (pendingnodes.empty())
            {
                return false;
            }
            else
            {
                if (s[i] == ']' && pendingnodes.top() != '[')
                {
                    return false;
                }
                else if (s[i] == '}' && pendingnodes.top() != '{')
                {
                    return false;
                }
                else if (s[i] == ')' && pendingnodes.top() != '(')
                {
                    return false;
                }
                pendingnodes.pop();
            }
        }
    }
    if (pendingnodes.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    cout << "Enter String: " << endl;
    string s;
    getline(cin, s);
    cout << isValid(s);
}