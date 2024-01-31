#include <iostream>
#include <climits>
using namespace std;

int answer(int **matrix, int rowans, int colans, int row, int col, int nrow, int ncol, bool **visited)
{
    if (row == rowans && col == colans)
    {
        return 0;
    }
    if (row > nrow - 1 || col > ncol - 1 || row < 0 || col < 0)
    {
        return -1;  // Return -1 to indicate unreachable target
    }
    if (visited[row][col])
    {
        return -1;  // Return -1 to indicate unreachable target
    }
    visited[row][col] = true;
    int up = answer(matrix, rowans, colans, row - 1, col, nrow, ncol, visited);
    int down = answer(matrix, rowans, colans, row + 1, col, nrow, ncol, visited);
    int left = answer(matrix, rowans, colans, row, col - 1, nrow, ncol, visited);
    int right = answer(matrix, rowans, colans, row, col + 1, nrow, ncol, visited);

    visited[row][col] = false;

    if (up == -1 || down == -1 || left == -1 || right == -1)
    {
        return -1;
    }

    return min(up, min(down, min(left, right))) + 1;
}

int main()
{
    int nrow, ncol, row, col;
    cin >> nrow >> ncol;

    int **matrix = new int *[nrow];
    for (int i = 0; i < nrow; i++)
    {
        matrix[i] = new int[ncol];
        for (int j = 0; j < ncol; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0)
            {
                row = i;
                col = j;
            }
        }
    }

    bool **visited = new bool *[nrow];
    for (int i = 0; i < nrow; i++)
    {
        visited[i] = new bool[ncol];
        fill(visited[i], visited[i] + ncol, false);
    }

    int rowans, colans;
    cin >> rowans >> colans;

    int result = answer(matrix, rowans, colans, row, col, nrow, ncol, visited);

    if (result == -1)
    {
        cout << "Target is unreachable." << endl;
    }
    else
    {
        cout << result;
    }

    for (int i = 0; i < nrow; i++)
    {
        delete[] matrix[i];
        delete[] visited[i];
    }
    delete[] matrix;
    delete[] visited;

    return 0;
}
