// #include <iostream>
// #include<algorithm>
// #include<climits>
// #include <vector>
// using namespace std;

// int minPathSum(vector<vector<int>> &grid,int m,int n, int i, int j) {
//     if (i == m - 1 && j == n - 1) {
//         return grid[i][j];
//     }
//     if (i >= m || j >= n) {
//         return 1e9;
//     }
//     int right = grid[i][j] + minPathSum(grid,m,n, i + 1, j);
//     int down =  grid[i][j] + minPathSum(grid,m,n, i, j + 1);
//     return min(right, down);
// }

// int main() {
//     cout << "Enter Number of rows and columns:";
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> ans(m, vector<int>(n,0));
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> ans[i][j];
//         }
//     }
//     cout << minPathSum(ans, m,n, 0, 0);
//     return 0;
// }

// #include <iostream>
// #include<algorithm>
// #include<climits>
// #include <vector>
// using namespace std;

// int minPathSum(vector<vector<int>> &grid,vector<vector<int>> ans,int m,int n, int i, int j) {
//     if (i == m - 1 && j == n - 1) {
//         return grid[i][j];
//     }
//     if (i >= m || j >= n) {
//         return 1e9;
//     }
//     if(ans[i][j]!=-1)
//     {
//         return ans[i][j];
//     }
//     int right = grid[i][j] + minPathSum(grid,ans,m,n, i + 1, j);
//     int down =  grid[i][j] + minPathSum(grid,ans,m,n, i, j + 1);
//     ans[i][j]=min(right,down);
//     return ans[i][j];
// }

// int main() {
//     cout << "Enter Number of rows and columns:";
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> ans(m, vector<int>(n,0));
//     vector<vector<int>> ans1(m, vector<int>(n,-1));
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> ans[i][j];
//         }
//     }
//     cout << minPathSum(ans,ans1,m,n, 0, 0);
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// int minPathSum(vector<vector<int>> &grid,vector<vector<int>> ans,int m,int n, int i, int j) {
//     if (i == m - 1 && j == n - 1) {
//         return grid[i][j];
//     }
//     if (i >= m || j >= n) {
//         return 1e9;
//     }
//     if(ans[i][j]!=-1)
//     {
//         return ans[i][j];
//     }
//     int right = grid[i][j] + minPathSum(grid,ans,m,n, i + 1, j);
//     int down =  grid[i][j] + minPathSum(grid,ans,m,n, i, j + 1);
//     ans[i][j]=min(right,down);
//     return ans[i][j];
// }
// third answer
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int curr=0;
    int prev1=0;
    int prev2=0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                prev1=curr;
                prev2=curr;
                curr = grid[i][j];
            }
            else if (i == 0)
            {
                curr = prev1+ grid[i][j];
                prev1=curr;
            }
            else if (j == 0)
            {
                curr = prev2 + grid[i][j];
                prev2=curr;
            }
            else
            {
                curr= min(prev1,prev2) + grid[i][j];
                prev1=curr;
                prev2=curr;
            }
        }
    }
    return curr;
}
int main()
{
    cout << "Enter Number of rows and columns:";
    int m, n;
    cin >> m >> n;
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ans[i][j];
        }
    }
    cout << minPathSum(ans);
    return 0;
}
