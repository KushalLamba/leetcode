#include<bits/stdc++.h>
using namespace std;
void printsol(vector<int> path)
{
    cout<<"It is one of the sol: "<<endl;
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    //cout<<path[0]<<endl;
}
bool isSafe(vector<vector<int>>& graph,vector<int>& path,int pos,int v)
{
    if(graph[path[pos-1]][v]==0)
    {
        return false;
    }
    for(int i=0;i<pos;i++)
    {
        if(path[i]==v) return false;
    }
    return true;
}
bool hamilcheck(vector<vector<int>>& graph,vector<int>& path,int pos)
{
    if(graph.size()==pos)
    {
        // if(graph[path[pos-1]][path[0]]==1) return true;
        // else 
        // return false;
        return true;
    }
    for(int v=1;v<graph.size();v++)
    {
        if(isSafe(graph,path,pos,v))
        {
            path[pos]=v;
            if(hamilcheck(graph,path,pos+1))
            {
                return true;
            }
            path[pos]=-1;
        }
    }
    return false;
}
bool hamicycle(vector<vector<int>> graph)
{
    vector<int> path(graph.size(),-1);
    path[0]=0;
    if(!hamilcheck(graph,path,1))
    {
        return false;
    }
    printsol(path);
    return true;
}
int main()
{
    cout<<"Enter number of vertices and edges: "<<endl;
    int v,e;
    cin>>v>>e;
    vector<vector<int>> graph(v,vector<int>(v,0));
    cout<<"Enter Edges First and last vertices: "<<endl;
    for(int i=0;i<e;i++)
    {
        int s,f;
        cin>>f>>s;
        graph[s][f]=1;
        graph[f][s]=1;
    }
    hamicycle(graph);
}