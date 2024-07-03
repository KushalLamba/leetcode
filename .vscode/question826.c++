#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    vector<pair<int, int>> ans;
    for (int i = 0; i < difficulty.size(); i++)
    {
        ans.push_back(make_pair(difficulty[i], profit[i]));
    }
    sort(ans.begin(), ans.end());
    sort(worker.begin(), worker.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" ";
        cout<<worker[i]<<endl;
    }
    int i = 0, j = 0;
    int value = 0;
    int maxprofit = 0;
    while (i < ans.size() && j < worker.size())
    {
        if (worker[j] < ans[i].first)
        {
            cout<<maxprofit<<endl;
            value += maxprofit;
            j++;
        }
        else
        {
            maxprofit = max(maxprofit, profit[i]);
            i++;
        }
    }
    if (j < worker.size())
    {
        for (; j < worker.size(); j++)
            value += maxprofit;
    }
    return value;
}
int main()
{
    cout << "Enter Number Of Elements in Diffculty array: " << endl;
    int n;
    cin >> n;
    vector<int> difficulty(n, 0);
    vector<int> profit(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> difficulty[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    int m;
    cin >> m;
    vector<int> worker(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> worker[i];
    }
    cout<<maxProfitAssignment(difficulty,profit,worker);
}