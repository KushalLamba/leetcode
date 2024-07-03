#include<iostream>
#include<vector>
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
    for(int i=0;i<adjmat.size();i++)
    {
        cout<<i<<"->"<<" ";
        for(int j=0;j<adjmat[i].size();j++)
        {
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
}