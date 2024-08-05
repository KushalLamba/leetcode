#include<bits/stdc++.h>
using namespace std;
void toposort(unordered_map<int,vector<int>>& adjlist,vector<int>& visted,int pos,stack<int>& sort)
{
    if(visted[pos]) return;
    visted[pos]=true;
    for(int i=0;i<adjlist[pos].size();i++)
    {
        if(!visted[adjlist[pos][i]])
        {
            visted[adjlist[pos][i]]=true;
            toposort(adjlist,visted,adjlist[pos][i],sort);
        }
    }
    sort.push(pos);
    return ;
}
int main()
{
    return 0;
}