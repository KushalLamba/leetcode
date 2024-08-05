#include<bits/stdc++.h>
using namespace std;
int n;
int ans(vector<vector<int>>& grid,int row,int col,vector<vector<int>> dp)
{
    if(row==n-1 && col==n-1)
    {
        return grid[row][col];        
    }
    if(dp[row][col]!=-1)return dp[row][col];
    int left=INT_MAX;
    int down=INT_MAX;
    if(col+1<n) left=ans(grid,row,col+1,dp);
    if(row+1<n) down=ans(grid,row+1,col,dp);
    return dp[row][col]=grid[row][col]+min(left,down);
}
int main()
{
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<ans(grid,0,0,dp);
}