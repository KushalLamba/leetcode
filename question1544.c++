#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;
string makeGood(string s)
{
    if (s.empty()) return "";
    stack<char> ans;
    ans.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (!ans.empty() && (s[i] + 32 == ans.top() + 0 || s[i] == ans.top() + 32))
        {
            ans.pop();
        }
        else
            ans.push(s[i]);
    }
    string result;
    while (!ans.empty())
    {
        result.push_back(ans.top());
        ans.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    string s;
    cin >> s;
    cout << makeGood(s);
}