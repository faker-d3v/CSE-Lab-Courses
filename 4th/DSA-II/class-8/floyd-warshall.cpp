#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX // Representation of infinity

// Cost matrix to store distances between nodes
int distanceMatrix[100][100];

// Function to perform Floyd-Warshall algorithm
void floydWarshall(int numNodes) {
    for (int k = 0; k < numNodes;
         k++) { // Iterate through all intermediate nodes
        for (int i = 0; i < numNodes; i++) { // Iterate through all source nodes
            for (int j = 0; j < numNodes;
                 j++) { // Iterate through all destination nodes
                // Update distance if passing through node k gives a shorter
                // path
                if (distanceMatrix[i][k] != INF && distanceMatrix[k][j] != INF)
                    distanceMatrix[i][j] =
                        min(distanceMatrix[i][j],
                            distanceMatrix[i][k] + distanceMatrix[k][j]);
            }
        }
    }
}

int main() {
    int numNodes, numEdges;

    // Input number of nodes and edges
    cout << "Enter number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    // Initialize distance matrix
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (i == j)
                distanceMatrix[i][j] = 0; // Distance to self is 0
            else
                distanceMatrix[i][j] =
                    INF; // Initially set all other distances to infinity
        }
    }

    // Input edges and their weights
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        distanceMatrix[u][v] = weight; // For undirected graph, update both ways
        distanceMatrix[v][u] = weight;
    }

    // Display distance matrix before running Floyd-Warshall
    cout << "\nDistance Matrix Before Floyd-Warshall:" << endl;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cout << distanceMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Run Floyd-Warshall algorithm
    floydWarshall(numNodes);

    // Display distance matrix after running Floyd-Warshall
    cout << "\nDistance Matrix After Floyd-Warshall:" << endl;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cout << distanceMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
