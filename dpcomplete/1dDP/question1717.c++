#include <bits/stdc++.h>
using namespace std;
int maximumGain(string s, int x, int y)
{
    int value = 0;
    string checker = "ab";
    stack<char> ans;
    int i = 0;
    while (i < s.size())
    {
        if (!ans.empty())
        {
            cout << ans.top() << " " << s[i] << endl;
        }
        if (!ans.empty() && s[i] == 'a' && ans.top() == 'b')
        {
            value += y;
            ans.pop();
        }
        else
        {
            ans.push(s[i]);
        }
        i++;
    }
    while(!ans.empty())
    {
      ans.pop();
    }
    
    i=0;
    while (i < s.size())
    {
        if (!ans.empty())
        {
            cout << ans.top() << " " << s[i] << endl;
        }
        if (!ans.empty() && s[i] == 'a' && ans.top() == 'b')
        {
            value += y;
            ans.pop();
        }
        else
        {
            ans.push(s[i]);
        }
        i++;
    }
    return value;
}
int main()
{
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    cout << maximumGain(s, x, y);
    return 0;
}