#include<bits/stdc++.h>
using namespace std;
bool cycledetect(unordered_map<int,vector<int>>& adjalist,vector<bool> visited,int pos,vector<int> &parents)
{
    if(visited[pos]) return true;
    for(int i=0;i<adjalist[pos].size();i++)
    {
        if(parents[adjalist[pos][i]]==pos) continue;
        if(visited[adjalist[pos][i]]) return true;
        if(cycledetect(adjalist,visited,adjalist[pos][i],parents)) return true;
    }
    return false;
}
int main()
{
    return 0;
}