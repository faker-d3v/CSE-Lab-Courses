#include <bits/stdc++.h>
using namespace std;

// Adjacency list to represent the graph
// This is a vector that contains 100 separate vectors of int type
vector<int> adjacencyList[100];

// Arrays to track visited nodes and recursion stack status
int visited[100];
int recursionStack[100];

/**
 * Performs a Depth-First Search (DFS) to detect a cycle in a directed graph.
 *
 * @param currentNode - The node currently being explored.
 * @return true if a cycle is detected, false otherwise.
 */
bool hasCycleDFS(int currentNode) {
    // If the node is already in the recursion stack, a cycle exists
    if (recursionStack[currentNode] == 1)
        return true;

    // If the node has already been visited and is not part of a cycle
    if (visited[currentNode] == 1)
        return false;

    // Mark current node as visited and add it to recursion stack
    visited[currentNode] = 1;
    recursionStack[currentNode] = 1;

    // Explore all adjacent nodes
    for (int neighbor : adjacencyList[currentNode]) {
        if (hasCycleDFS(neighbor)) {
            return true; // Cycle detected
        }
    }

    // Remove the current node from recursion stack before returning
    recursionStack[currentNode] = 0;
    return false;
}

int main() {
    int numNodes, numEdges;

    cout << "Enter the number of nodes and edges: " << endl;
    cin >> numNodes >> numEdges;

    cout << "Enter the edge list (u v) for directed edges:" << endl;
    /*
        Example Input:
        5 6
        0 1
        1 3
        3 0
        2 3
        3 4
        4 2

        Becomes:
        0 - 1
        1 - 3
        2 - 3
        3 - 0, 4
        4 - 2
    */

    // Read edges and populate adjacency list
    for (int i = 0; i < numEdges; i++) {
        int fromNode, toNode;
        cin >> fromNode >> toNode;
        adjacencyList[fromNode].push_back(toNode); // Directed edge from -> to
    }

    cout << "Enter the source node to start DFS: " << endl;
    int startNode;
    cin >> startNode;

    // Run DFS to detect cycle
    if (hasCycleDFS(startNode))
        cout << "Cycle exists in the graph." << endl;
    else
        cout << "No cycle exists in the graph." << endl;

    return 0;
}
