#include<iostream>
#include<vector>
using namespace std;
void printgraph(vector<vector<int>> matrix,bool *visited,int sv=0)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<matrix.size();i++)
    {
        if(matrix[sv][i]==1 && !visited[i])
        {
            printgraph(matrix,visited,i);
        }
    }
}
int main()
{
    cout<<"Enter Number Of vertices and edges: "<<endl;
    int n,e;
    cin>>n>>e;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        matrix[f][s]=1;
        matrix[s][f]=1;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    printgraph(matrix,visited);
}