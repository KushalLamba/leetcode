#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Graph {
private:
    vector<set<int>> adjList;

public:
    Graph(int n) {
        adjList.resize(n);
    }

    void addEdge(int u, int v) {
        // Avoid adding repeated edges by using a set
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    void dfs(int sv, vector<bool>& visited) {
        visited[sv] = true;
        for (int neighbor : adjList[sv]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    bool isConnected() {
        vector<bool> visited(adjList.size(), false);
        int startNode = -1;

        // Find the first node with at least one edge to start DFS
        for (int i = 0; i < adjList.size(); i++) {
            if (!adjList[i].empty()) {
                startNode = i;
                break;
            }
        }

        // If there is no start node, the graph is trivially connected
        if (startNode == -1) {
            return true;
        }

        dfs(startNode, visited);

        // Check if all nodes with edges were visited
        for (int i = 0; i < adjList.size(); i++) {
            if (!visited[i] && !adjList[i].empty()) {
                return false;
            }
        }
        return true;
    }

    int findEulerian() {
        if (!isConnected()) {
            return 0; // Not connected, not Eulerian
        }

        int oddDegreeCount = 0;
        for (int i = 0; i < adjList.size(); i++) {
            if (adjList[i].size() % 2 != 0) {
                oddDegreeCount++;
            }
        }

        if (oddDegreeCount > 2) {
            return 0; // Not Eulerian
        } else if (oddDegreeCount == 2) {
            return 2; // Semi-Eulerian
        } else {
            return 1; // Eulerian
        }
    }
};

int main() {
    cout << "Enter number of vertices and edges: " << endl;
    int n, e;
    cin >> n >> e;

    Graph graph(n);

    cout << "Enter the edges (pairs of vertices):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int ans = graph.findEulerian();

    if (ans == 0) {
        cout << "Graph is not Eulerian" << endl;
    } else if (ans == 2) {
        cout << "Graph is semi-Eulerian" << endl;
    } else {
        cout << "Graph is Eulerian" << endl;
    }

    return 0;
}
