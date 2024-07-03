#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans(n, vector<int>());
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < ans[edges[i][0]].size(); j++)
        {
            ans[edges[i][1]].push_back(ans[edges[i][0]][j]);
        }
        ans[edges[i][1]].push_back(edges[i][0]);
    }
    return ans;
}
int main()
{
    cout << "Enter n: " << endl;
    int n;
    cin >> n;
    vector<vector<int>> edges(9, vector<int>(2));
    ;
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i][0];
        cin >> edges[i][1];
    }
    vector<vector<int>> ans=getAncestors(n,edges);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
