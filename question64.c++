#include <iostream>
#include<algorithm>
#include<climits>
#include <vector>
using namespace std;
int minPathSum(vector<vector<int>> &grid,int n,int i,int j)
{
    if (i == n && j == n)
    {
        return 0;
    }
    if (i > n - 1 || j > n - 1)
    {
        return INT_MAX;
    }
    int right = grid[i][j] + minPathSum(grid,n, i + 1, j);
    int down =  grid[i][j] + minPathSum(grid,n, i, j + 1);
    cout<<min(right,down);
    return min(right,down);
}
int main()
{
    cout << "Enter Number of rows and columns:";
    int m, n;
    cin >> m >> n;
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ans[i][j];
        }
    }
    cout<<minPathSum(ans,m,0,0);
}