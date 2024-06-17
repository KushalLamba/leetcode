#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findMaximizedCapital(int k, int w, vector<int> &profits,
                         vector<int> &capital)
{
    vector<pair<int, int>> combined;
    for (int i = 0; i < capital.size(); i++)
    {
        combined.push_back(make_pair(capital[i], profits[i]));
    }
    priority_queue<int> profitheap;
    int i = 0;
    for (int j = 0; j < k; j++)
    {
        for (; i < combined.size(); i++)
        {
            if (w >= combined[i].first)
            {
                profitheap.push(combined[i].second);
            }
            else
                break;
        }
        if (!profitheap.empty())
        {
            w = w + profitheap.top();
            profitheap.pop();
        }
    }
    return w;
}
int main()
{
    cout << "Enter Number Of Projects: " << endl;
    int n;
    cin >> n;
    vector<int> profits(n, 0);
    vector<int> capitals(n, 0);
    for (int i = 0; i < n; i++)
        cin >> profits[i];
    for (int i = 0; i < n; i++)
        cin >> capitals[i];
    cout << "Enter Value of W: " << endl;
    int w;
    cin >> w;
    cout << "Enter Value of K: " << endl;
    int k;
    cin >> k;
    cout << findMaximizedCapital(k, w, profits, capitals);
}