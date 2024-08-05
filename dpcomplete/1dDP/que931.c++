#include<bits/stdc++.h>
using namespace std;
//int n;
// top to bottom approch
// int finder(vector<vector<int>>& matrix,int row,int col)
// {
//     if(row==n-1)
//     {
//         return matrix[row][col];
//     }
//     int mincost=INT_MAX;
//     if(col-1>=0) mincost=min(mincost,finder(matrix,row+1,col-1));
//     if(col+1<n) mincost=min(mincost,finder(matrix,row+1,col+1));
//     mincost=min(mincost,finder(matrix,row+1,col));
//     return mincost+matrix[row][col];
// }
// int minFallingSum(vector<vector<int>>& matrix)
// {
//     int mincost=INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//        int ans=finder(matrix,0,i);
//        mincost=min(ans,mincost);
//     }
//     return mincost;
// }
// bottom to up approch
int minFallingPathSum(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++)
    {
        dp[0][i]=matrix[0][i];
    }
    for(int row=1;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
           if(col-1>=0) dp[row][col]=min(dp[row][col],dp[row-1][col-1]);
           if(col+1<n) dp[row][col]=min(dp[row][col+1],dp[row-1][col+1]);
           dp[row][col]=matrix[row][col]+min(dp[row][col],dp[row-1][col-1]);
        }
    }
    int mincost=INT_MAX;
    for(int i=0;i<n;i++)
    {
        mincost=min(dp[n-1][i],mincost);
    }
    return mincost;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<minFallingPathSum(matrix);
}