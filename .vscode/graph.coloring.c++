#include <bits/stdc++.h>
using namespace std;
void printSolution(vector<int> color)
{
    cout << "Solution Exists:"
         << " Following are the assigned colors"
         << "\n";
    for (int i = 0; i <color.size(); i++)
        cout << " " << color[i] << " ";

    cout << "\n";
}

bool issafe(vector<vector<int>> graph, vector<int> &color, int pos, int c)
{
    for (int i = 0; i < pos; i++)
    {
        if (graph[pos][i] && color[i] == c)
        {
            return false;
        }
    }
    return true;
}
bool graphuntil(vector<vector<int>> graph, vector<int> &color, int m, int pos = 0)
{
    if (graph.size() == pos)
    {
        return true;
    }
    for (int c = 1; c <= m; c++)
    {
        if (issafe(graph, color, pos, c))
        {
            color[pos] = c;
            if (graphuntil(graph, color, m, pos + 1) == true)
            {
                return true;
            }
            color[pos] = 0;
        }
    }
    return false;
}
bool graphcoloring(vector<vector<int>> graph, int m)
{
    vector<int> color(graph.size(), 0);
    if (graphuntil(graph, color, m) == false)
    {
        cout << "No soln exists" << endl;
        return false;
    }
    printSolution(color);
    return true;
}
int main()
{
    cout << "Enter number Of Vertices and edges: " << endl;
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    cout << "Enter Number Of Colurs: " << endl;
    int m;
    cin >> m;
    graphcoloring(graph, m);
}