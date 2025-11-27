#include <bits/stdc++.h>
using namespace std;

// Vector of 100 vectors of type int
vector<int> adjacencyList[100];

// visited[i] = 1 means node i has been discovered
int visited[100];

// distanceFromSource[i] stores the shortest distance from the source node to i
int distanceFromSource[100];

// Performs BFS from 'source' until 'destination' is reached
// Logic unchanged—only cleaned and documented
void bfs(int source, int destination) {
    queue<int> nodeQueue; // Queue for BFS processing

    visited[source] = 1;            // Mark source as visited
    distanceFromSource[source] = 0; // Distance to itself is 0
    nodeQueue.push(source);         // Start BFS

    while (!nodeQueue.empty()) {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        // Traverse all neighbors of currentNode
        for (int i = 0; i < adjacencyList[currentNode].size(); i++) {
            int neighbor = adjacencyList[currentNode][i];

            // If neighbor hasn't been visited, visit it and assign distance
            if (visited[neighbor] == 0) {
                nodeQueue.push(neighbor);
                visited[neighbor] = 1;

                // Distance to neighbor = distance to current + 1
                distanceFromSource[neighbor] =
                    distanceFromSource[currentNode] + 1;
            }

            // Early exit if destination is found
            if (neighbor == destination)
                return;
        }
    }
}

int main() {
    int nodes, edges, u, v, destination;

    cout << "Enter the number of nodes and edges: " << endl;
    cin >> nodes >> edges;

    cout << "Enter the edge list (undirected edges):" << endl;

    // Read edges and build the adjacency list
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // Because the graph is undirected
    }

    cout << "Enter the source and destination nodes: " << endl;
    int source;
    cin >> source >> destination;

    // Run BFS to compute shortest path distance
    bfs(source, destination);

    cout << "Using BFS, the shortest path distance is: ";
    cout << distanceFromSource[destination] << endl;

    return 0;
}
