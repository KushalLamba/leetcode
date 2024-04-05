#include <iostream>
#include <vector>
using namespace std;

bool checkpos(const vector<vector<int>>& queen, int row, int col) {
    int i, j;
    // Check horizontally left
    for (i = col - 1; i >= 0; i--) {
        if (queen[row][i] == 1)
            return false;
    }
    // Check upper diagonal left
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (queen[i][j] == 1)
            return false;
    }
    // Check lower diagonal left
    for (i = row + 1, j = col - 1; i < queen.size() && j >= 0; i++, j--) {
        if (queen[i][j] == 1)
            return false;
    }
    return true;
}

vector<vector<pair<int, int>>> solvenqueen(vector<vector<int>>& queen, int col) {
    int n = queen.size();
    vector<vector<pair<int, int>>> output;
    if (col >= n) {
        vector<pair<int, int>> solution;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (queen[i][j] == 1)
                    solution.push_back(make_pair(i, j));
            }
        }
        output.push_back(solution);
        return output;
    }
    for (int i = 0; i < n; i++) {
        if (checkpos(queen, i, col)) {
            queen[i][col] = 1;
            vector<vector<pair<int, int>>> temp = solvenqueen(queen, col + 1);
            output.insert(output.end(), temp.begin(), temp.end());
            queen[i][col] = 0;
        }
    }
    return output;
}

int main() {
    cout << "Enter Number of Queens Want to be placed: " << endl;
    int n;
    cin >> n;
    vector<vector<int>> queen(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> ans = solvenqueen(queen, 0);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << "(" << ans[i][j].first << "," << ans[i][j].second << ") ";
        }
        cout << endl;
    }
    return 0;
}
