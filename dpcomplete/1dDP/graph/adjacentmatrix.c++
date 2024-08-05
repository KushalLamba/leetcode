#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    // Example adjacency matrix represented as a vector of pairs (edges)
    vector<vector<int>> adjmatrix = {{1,0}, {2,0}, {2, 1}, {3,1}};
    
    unordered_map<int, vector<int>> adjlist;
    
    // Convert adjacency matrix to adjacency list
    for (int i = 0; i < adjmatrix.size(); i++) {
        adjlist[adjmatrix[i][1]].push_back(adjmatrix[i][0]);
    }
    int v;
    cin>>v;
    // Print adjacency list
    for (int i=0;i<v;i++) {
        cout <<i<<"-->";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout << endl;
    }
    
    return 0;
}