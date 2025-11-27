#include <bits/stdc++.h>
using namespace std;

static const int INF = 10000000;

vector<int> adj[100];     // adjacency list (neighbors)
vector<int> adjCost[100]; // corresponding edge weights
int visited[100];         // not used, but kept since part of original structure
int distCost[100];        // shortest distance array

// Dijkstra's algorithm (min-heap based)
void dijkstra(int source) {
    // priority_queue holds pairs of (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, source});
    distCost[source] = 0;

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();

        // Explore all neighbors of the current node
        for (int i = 0; i < adj[current].size(); i++) {
            int neighbor = adj[current][i];
            int weight = adjCost[current][i];

            // Relax the edge if a shorter path is found
            if (distCost[neighbor] > distCost[current] + weight) {
                distCost[neighbor] = distCost[current] + weight;
                pq.push({distCost[neighbor], neighbor});
            }
        }
    }
}

int main() {
    int nodes, edges;
    int u, v, w;

    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    // Initialize all distances to INF
    for (int i = 0; i <= nodes; i++)
        distCost[i] = INF;

    cout << "Enter edges in format [u v weight]:" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adjCost[u].push_back(w);
        adj[v].push_back(u); // undirected graph
        adjCost[v].push_back(w);
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    dijkstra(source);

    cout << "Shortest distances from source: " << endl;
    for (int i = 0; i < nodes; i++) {
        cout << distCost[i] << " ";
    }
    cout << endl;

    return 0;
}
