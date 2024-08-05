#include <bits/stdc++.h>
using namespace std;

void dfs(vector<bool> &visited,unordered_map<int,vector<int>>& adjlist,int pos)
{
    if (visited[pos])
        return;
    cout << pos << " ";
    visited[pos] = true;
    for (int i = 0; i < adjlist[pos].size(); i++)
    {
        if (!visited[adjlist[pos][i]])
        {
            dfs(visited,adjlist,adjlist[pos][i]);
        }
    }
    return;
}
void bfs(vector<bool> &visited,unordered_map<int,vector<int>>& adjalist)
{

    queue<int> pendingnodes;
    pendingnodes.push(0);
    visited[0]=true;
    while(!pendingnodes.empty())
    {
        int front=pendingnodes.front();
        pendingnodes.pop();
        cout<<front<<" ";
        for(int i=0;i<adjalist[front].size();i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                pendingnodes.push(adjalist[front][i]);
            }
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adjmatrix(n, vector<int>(2));
    for (int i = 0; i < adjmatrix.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> adjmatrix[i][j];
        }
    }
    int v;
    cin >> v;
    unordered_map<int, vector<int>> adjlist;
    for (int i = 0; i < adjmatrix.size(); i++)
    {
        adjlist[adjmatrix[i][1]].push_back(adjmatrix[i][0]);
    }
    vector<bool> visited(v,false);
    //dfs(visited,adjlist,0);
    bfs(visited,adjlist);
}