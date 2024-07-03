#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s1, string s2)
{
    unordered_map<int, int> first;
    unordered_map<int, int> second;
    for (int i = 0; i < s2.size(); i++)
    {
        second[s2[i]]++;
    }
    string s;
    int start = 0, sum = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (second.count(s1[i]) > 0)
        {
            first[s1[i]]++;
            if (first[s1[i]] <= second[s1[i]])
                sum++;
        }
        if (start<s1.size() && sum == s2.size())
        {
            while (second.count(s1[start]) == 0 || second[s1[start]]!=first[s1[start]])
            {
                if (first.count(s1[start]) != 0)
                        first[s1[start]]--;
                start++;
            }
            sum--;
            first[s1[start]]--;
            if (s.length() == 0 || s.length() > i - start + 1)
                s = s1.substr(start, i - start+1);
            start++;
        }
    }
    return s;
}
int main()
{
    string s1, s2;
    cout << "Enter String 1: " << endl;
    cin >> s1;
    cout << "Enter String 2: " << endl;
    cin >> s2;
    cout << minWindow(s1, s2);
}