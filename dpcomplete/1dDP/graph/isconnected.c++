#include<bits/stdc++.h>
using namespace std;
void connected(unordered_map<int,vector<int>>& adjlist,vector<int>& visited,int pos)
{
    queue<int> pendingnodes;
    pendingnodes.push(pos);
    visited[pos]=true;
    while(!pendingnodes.empty())
    {
        int front=pendingnodes.front();
        pendingnodes.pop();
        for(int i=0;i<adjlist[front].size();i++)
        {
            if(!visited[adjlist[front][i]])
            {
                visited[adjlist[front][i]]=true;
                pendingnodes.push(adjlist[front][i]);
            }
        }
    }
    return;
}
int provience(vector<vector<int>> adjmatrix,int v)
{
    int count=0;
    vector<int> visited(v,false);
    unordered_map<int, vector<int>> adjlist;
    for (int i = 0; i < adjmatrix.size(); i++)
    {
        adjlist[adjmatrix[i][1]].push_back(adjmatrix[i][0]);
    }
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            count++;
            connected(adjlist,visited,i);
        }
    }
    return count;
}
int main()
{
    
}