#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>> &grid) {
    if (grid.empty())
        return 0;

    int m = grid.size();
    int n = grid[0].size();
    int sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int count = 4;

                if (j + 1 < n && grid[i][j + 1] == 1)
                    count--;
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                    count--;
                if (i + 1 < m && grid[i + 1][j] == 1)
                    count--;
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                    count--;

                sum += count;
            }
        }
    }

    return sum;
}

int main() {
    int m, n;
    cout << "Enter Number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter the grid:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Perimeter of islands: " << islandPerimeter(grid) << endl;
    return 0;
}
