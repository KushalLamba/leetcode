#include <bits/stdc++.h>
using namespace std;
bool check(string s, unordered_map<char, int> count)
{
    unordered_map<char, int> first;
    for (int i = 0; i < s.size(); i++)
    {
        first[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (first[s[i]] != count[s[i]])
            return false;
    }
    return true;
}
int finder(string s, int start, int pos, unordered_map<char, int> &count)
{
    if (pos == s.size())
    {
        return (pos - start) * (pos - start);
    }
    int take = INT_MAX;
    if (check(s.substr(start, pos - start + 1), count))
    {
        int value = (pos - start + 1) * (pos - start + 1);
        take = value + finder(s, pos + 1, pos + 1, count);
    }
    int nottake = finder(s, start, pos + 1, count);
    return min(take, nottake);
}
int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> count;
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i]]++;
    }
    cout << finder(s, 0, 0, count);
}