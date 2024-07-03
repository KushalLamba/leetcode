#include <bits/stdc++.h>
using namespace std;
string frequencysSort(string s)
{
    unordered_map<char, int> check;
    for (int i = 0; i < s.size(); i++)
    {
        check[s[i]]++;
    }
    vector<pair<int, char>> ans;
    for (auto& it: check)
    {
        ans.push_back(make_pair(it.second, it.first));
    }
    sort(ans.begin(), ans.end(), [](pair<int, char> &a, pair<int, char> &b)
         { return a.first > b.first; });
    string value;
    for (int i = 0; i < ans.size(); i++)
    {
        value += ans[i].second;
    }
    return value;
}
int main()
{
    cout << "Enter string: " << endl;
    string s;
    cin >> s;
    cout << frequencysSort(s);
}