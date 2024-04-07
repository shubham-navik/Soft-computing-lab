#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


unordered_map<int, vector<int>> adj;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool DLS(int currentVertex, int targetNode, int depth, unordered_map<int, bool>& visited) {

    if (currentVertex == targetNode) {
        return true; // Target node found
    }

    if (depth > 0) {
        visited[currentVertex] = true;

        for (int neighbor : adj[currentVertex]) {
            if (!visited[neighbor] && DLS(neighbor, targetNode, depth - 1, visited)) {
                return true;
            }
        }

        visited[currentVertex] = false; // Backtrack
    }


    return false; // Target node not found at the specified depth
}



bool depthLimitedSearch(int startVertex, int targetNode, int maxDepth) {
    unordered_map<int, bool> visited; // Initialize all vertices as not visited
    return DLS(startVertex, targetNode, maxDepth, visited);
}


int main() {
    // Add edges to the graph

    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(3, 4);
    addEdge(5, 6);
    addEdge(4, 6);
    addEdge(4, 7);
    addEdge(7, 8);
    addEdge(6, 9);
    addEdge(8, 10);
    addEdge(9, 10);

    int startNode = 1;
    int targetNode = 0;
    int maxDepth = 7; // Maximum depth to search

    // cout << "Searching for target node " << targetNode << " starting from vertex " << startNode << " with a depth limit of " << maxDepth << ": ";
    if (depthLimitedSearch(startNode, targetNode, maxDepth)) {
        cout << "Target node found." << endl;
    } else {
        cout << "Target node not found." << endl;
    }

    return 0;
}
