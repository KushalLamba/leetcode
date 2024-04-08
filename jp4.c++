#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int soln(vector<vector<int>> board,vector<int> output,int row = 0, int col = 0)
{
    int rightsum = 0;
    int downsum = 0;
    int m = board.size();
    int n = board[0].size();
    if (row == m - 1 && col == n - 1)
    {
        
    }
    if (row < m && col < n)
    {
        rightsum += soln(board,output,row, col + 1) + board[row][col];
        downsum += soln(board,output,row + 1, col)+board[row][col];
        output.push_back(rightsum);
        output.push_back(downsum);
        return rightsum+downsum;
    }
}
int main()
{
    cout << "Enter Number of rows and columns: " << endl;
    int row, col;
    cin >> row >> col;
    vector<vector<int>> ans(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> ans[i][j];
        }
    }
    vector<int> solutions;
    cout<<soln(ans,solutions);
}