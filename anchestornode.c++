#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> getmatrix(int n, vector<vector<int>> edges)
{
    vector<vector<int>> adjmat(n, vector<int>());
    for (int i = 0; i < edges.size(); i++)
    {
        adjmat[edges[i][0]].push_back(edges[i][1]);
    }
    return adjmat;
}
vector<int> gettopsort(int n, vector<vector<int>> adjmat, vector<vector<int>> edges)
{
    vector<int> indegree(n, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        indegree[edges[i][1]]++;
    }
    queue<int> pendingnodes;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            pendingnodes.push(i);
    }
    vector<int> ans;
    while (!pendingnodes.empty())
    {
        int front = pendingnodes.front();
        pendingnodes.pop();
        ans.push_back(front);
        for (int i = 0; i < adjmat[front].size(); i++)
        {
            indegree[adjmat[front][i]]--;
            if (indegree[adjmat[front][i]] == 0)
                pendingnodes.push(adjmat[front][i]);
        }
    }
    return ans;
}
vector<vector<int>> getAncestors(int n, vector<vector<int>> edges)
{
    vector<set<int>> ans(n);
    vector<vector<int>> adjmat = getmatrix(n, edges);
    vector<int> topsort = gettopsort(n, adjmat, edges);
    for (int i = 0; i < topsort.size(); i++)
    {
        int value = topsort[i];
        for (int j = 0; j < adjmat[value].size(); j++)
        {
            ans[adjmat[value][j]].insert(value);
            ans[adjmat[value][j]].insert(ans[value].begin(), ans[value].end());
        }
    }
    vector<vector<int>> result(n, vector<int>());
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int ancestor : ans[i])
        {
            result[i].push_back(ancestor);
        }
    }
    return result;
}
int main()
{
    cout << "Enter Number Of Vertices and edges: " << endl;
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> edges[i][j];
        }
    }
}