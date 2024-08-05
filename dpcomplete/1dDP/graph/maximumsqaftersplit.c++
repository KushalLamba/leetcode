#include <bits/stdc++.h>
using namespace std;
int helper(string s, int zero, int one, int pos)
{
    if (pos == s.size())
        return 0;
    if (s[pos] == '0')
        zero++;
    if (s[pos] == '1')
        one--;
    int maxv = 0;
    int take = zero + one;
    maxv = helper(s, zero, one, pos + 1);
    maxv = max(maxv, take);
    return maxv;
}
int maxscore(string s)
{
    int one = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            one++;
    }
    return helper(s, 0, one, 0);
}
int main()
{
    string s;
    cin >> s;
    cout << maxscore(s);
}