#include <iostream>
#include <vector>
using namespace std;
bool checkpos(vector<vector<int>> board, int row, int col, int n)
{
    int i = 0, j = 0;
    for (j = col - 1; j >= 0; j--)
    {
        if (board[row][j] == 1) return false;
    }
    for (i = 0, j = col; i < n && j >= 0; i++, j--)
    {
        if(board[i][j]==1) return false;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1) return false;
    }
    return true;
}
vector<vector<pair<int, int>>> solvenqueen(vector<vector<int>> board, int col)
{
    int n = board.size();
    vector<vector<pair<int, int>>> output;
    if (col >= n)
    {
        vector<pair<int, int>> solution;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    solution.push_back(make_pair(i, j));
            }
        }
        output.push_back(solution);
        return output;
    }
    for (int i = 0; i < n; i++)
    {
        if (checkpos(board, i, col, n))
        {
            board[i][col] = 1;
            vector<vector<pair<int, int>>> value = solvenqueen(board, col + 1);
            output.insert(output.end(), value.begin(), value.end());
            board[i][col] = 0;
        }
    }
    return output;
}
int main()
{
    cout << "Enter Number Of Queens Placed: " << endl;
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> ans = solvenqueen(board, 0);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j].first<<" "<<ans[i][j].second<<" ";
        }
    }
}