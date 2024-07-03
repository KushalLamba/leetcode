#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter Number Of Vertices and Edges: "<<endl;
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges(e,vector<int>(2));
    for(int i=0;i<e;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>edges[i][j];
        }
    }
    vector<vector<int>> adjmat(v,vector<int>());
    for(int i=0;i<edges.size();i++)
    {
        adjmat[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> indegree(v,0);
    for(int i=0;i<edges.size();i++)
    {
        indegree[edges[i][1]]++;
    }
    queue<int> pendingnodes;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0) pendingnodes.push(i);
    }
    vector<int> result;
    while(!pendingnodes.empty())
    {
        int front=pendingnodes.front();
        pendingnodes.pop();
        result.push_back(front);
        for(int i=0;i<adjmat[front].size();i++)
        {
            indegree[adjmat[front][i]]--;
            if(indegree[adjmat[front][i]]==0) pendingnodes.push(adjmat[front][i]);
        }
    }
    cout<<"Result is topsort"<<endl;
}