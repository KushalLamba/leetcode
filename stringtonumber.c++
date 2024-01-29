#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    long x = 0;
    int flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
        {
            flag = 1;
        }
        else if (s[i] > '0' && s[i] <= '9')
        {
            x = x * 10 + s[i]-'0';
        }
        else if (s[i] == ' ')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    if (flag == 1)
        return -x;
    if (x > INT_MAX/10)
    {
        return INT_MAX;
    }
    else if (x < INT_MIN/10)
        return INT_MIN;
    return x;
}
int main()
{
    string s;
    cout << "Enter The String: " << endl;
    getline(cin, s);
    cout << myAtoi(s);
    //cout<<INT_MIN;
}