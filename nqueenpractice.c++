#include <iostream>
#include <vector>
using namespace std;
int count = 0;
bool checkpos(vector<vector<int>> queen, int row, int col)
{
    int i, j;
    for (int i = col - 1; i >= 0; i--)
    {
        if (queen[row][i] == 1)
        {
            return false;
        }
    }
    i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (queen[i][j] == 1)
        {
            return false;
        }
        i--, j--;
    }
    i = row + 1, j = col - 1;
    while (i < queen.size() && j >= 0)
    {
        if (queen[i][j] == 1)
        {
            return false;
        }
        i++, j--;
    }
    return true;
}
vector<vector<pair<int, int>>> solvenqueen(vector<vector<int>> queen, int col)
{
    int n = queen.size();
    vector<vector<pair<int, int>>> output;
    if (col >= n)
    {
        vector<pair<int, int>> solutions;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (queen[i][j] == 1)
                {
                    solutions.push_back(make_pair(i, j));
                }
            }
        }
        output.push_back(solutions);
        return output;
    }
    for (int i = 0; i < n; i++)
    {
        if (checkpos(queen, i, col))
        {
            queen[i][col] = 1;
            vector<vector<pair<int, int>>> ans = solvenqueen(queen, col + 1);
            output.insert(output.end(), ans.begin(), ans.end());
            queen[i][col] = 0;
        }
    }
    return output;
}
int main()
{
    cout << "Enter Number Of Queens: " << endl;
    int n;
    cin >> n;
    vector<vector<int>> queen(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> output = solvenqueen(queen, 0);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << "( " << output[i][j].first << "," << output[i][j].second << " ) ";
        }
        cout << endl;
    }
}