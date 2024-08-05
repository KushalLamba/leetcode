#include<bits/stdc++.h>
using namespace std;
bool cycledete(unordered_map<int,vector<int>>& adjlist,int v,vector<bool> visited)
{
    queue<int> pendingnodes;
    pendingnodes.push(0);
    vector<int> parent(v,0);
    parent[0]=-1;
    while(!pendingnodes.empty())
    {
        int front=pendingnodes.front();
        pendingnodes.pop();
        for(int i=0;i<adjlist[front].size();i++)
        {
            if(parent[adjlist[front][i]]==front) continue;
            else if(visited[adjlist[front][i]]) return false;
            else
            {
                parent[adjlist[front][i]]=front;
                visited[adjlist[front][i]]=true;
                pendingnodes.push(adjlist[front][i]);
            }
        }
        return true;
    }
}
int main()
{
    return 0;
}