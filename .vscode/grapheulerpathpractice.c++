#include <bits/stdc++.h>
using namespace std;
class graph
{
private:
    vector<set<int>> matrix;

public:
    graph(int n)
    {
        matrix.resize(n);
    }
    void addvertices(int u, int v)
    {
        matrix[u].insert(v);
        matrix[v].insert(u);
    }
    void dfs(vector<bool>& visited, int start)
    {
        visited[start] = true;
        for (int neighbor : matrix[start]) {
            if (!visited[neighbor]) {
                dfs(visited,neighbor);
            }
        }
    }
    bool isconnected()
    {
        int start = -1;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i].size() > 0)
            {
                start = i;
                break;
            }
        }
        if (start == -1)
            return true;
        vector<bool> visited(matrix.size(), false);
        dfs(visited, start);
        for (int i = 0; i < matrix.size(); i++)
        {
            if (!visited[i] &&!matrix[i].empty())
            {
                return false;
            }
        }
        return true;
    }
    int findeuler()
    {
        if (!isconnected())
        {
            return 0;
        }
        int odd = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i].size() % 2 != 0)
                odd++;
        }
        if (odd > 2)
        {
            return 0; // Not Eulerian
        }
        else if (odd == 2)
        {
            return 2; // Semi-Eulerian
        }
        else
        {
            return 1; // Eulerian
        }
    }
};
int main()
{
    cout << "Enter Number Of Vertices and Edges: " << endl;
    int v, e;
    cin >> v >> e;
    graph Graph(v);
    cout << "Enter Pair Of Vertices: " << endl;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        Graph.addvertices(f, s);
    }
    int ans = Graph.findeuler();
    if (ans == 0)
    {
        cout << "It is not Euleranian Graph" << endl;
    }
    else if (ans == 2)
    {
        cout << "It is SemiEulerian Graph" << endl;
    }
    else
    {
        cout << "It is eularian Graph" << endl;
    }
}