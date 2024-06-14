#include <iostream>
#include <vector>
using namespace std;

// Function to print the Hamiltonian cycle
void printSolution(const vector<int>& path) {
    cout << "One Hamiltonian Cycle found: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << path[0] << endl;
}

// Function to check if the current vertex can be added to the path
bool isSafe(const vector<vector<int>>& graph, const vector<int>& path, int pos, int v) {
    // Check if there is an edge between the current position and vertex v
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }
    // Check if the vertex v has already been included in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }
    return true;
}

// Recursive function to find a Hamiltonian cycle
bool hamilCheck(const vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (pos == graph.size()) {
        // Check if there is an edge from the last vertex in the path to the starting vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }

    // Try adding each vertex from 1 to the last vertex in the graph
    for (int v = 1; v < graph.size(); v++) {
        // Check if vertex v can be safely added to the path at position pos
        if (isSafe(graph, path, pos, v)) {
            path[pos] = v; // Add vertex v to the path
            if (hamilCheck(graph, path, pos + 1)) {
                return true;
            }
            // Backtrack if not a valid path
            path[pos] = -1;
        }
    }
    return false;
}

// Function to find a Hamiltonian cycle
bool hamiCycle(const vector<vector<int>>& graph) {
    // Initialize the path with the starting vertex
    vector<int> path(graph.size(), -1);
    path[0] = 0; // Start from vertex 0

    // Check if a Hamiltonian cycle is found
    if (!hamilCheck(graph, path, 1)) {
        cout << "No Hamiltonian Cycle found." << endl;
        return false;
    }

    // Print the found Hamiltonian cycle
    printSolution(path);
    return true;
}

int main() {
    cout << "Enter number of vertices and edges: " << endl;
    int v, e;
    cin >> v >> e;

    // Initialize the adjacency matrix with 0 (no edge)
    vector<vector<int>> graph(v, vector<int>(v, 0));

    cout << "Enter edges (start and end vertices): " << endl;
    for (int i = 0; i < e; i++) {
        int s, f;
        cin >> s >> f;
        graph[s][f] = 1;
        graph[f][s] = 1;
    }

    // Find a Hamiltonian cycle
    bool hasCycle = hamiCycle(graph);

    return 0;
}
