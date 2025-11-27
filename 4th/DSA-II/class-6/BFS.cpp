#include <bits/stdc++.h>
using namespace std ;

void PrintVector(vector<int> v) {
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> bfs(vector<vector<int>> &adj) {
    int len = adj.size(); // size of the vector 
    int start = 0;  // source node
    vector<int> res; // traversal result
    
    // empty queue for BFS
    queue<int> q; 

    // mark all verteices as unvisited
    vector<bool> visited(len, false);

    // mark source visited
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        // dequeue a vertext from queue and hold on to it
        int current = q.front();
        q.pop();

        // add it to the result
        res.push_back(current);

        // fetch all the adjacent nodes of "current" 
        for (int x: adj[current]) {
            // if not visited mark as visited and push to the queue
            if (!visited[x])   {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return res;
}

int main() {
    vector<vector<int>> adjl = {
        {1,2},
        {0,2,3},
        {0,4},
        {1,4},
        {2,3},
    };
    // cout << "lit" << endl;
    // PrintVector(adj[1]);
    vector<int> res = bfs(adjl);
    PrintVector(res);
}




