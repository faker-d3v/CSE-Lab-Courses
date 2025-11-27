#include "bits/stdc++.h"
using namespace std;

void PrintVector(vector<int> v) { 
    for (int i: v) { 
        cout << i << " ";
    } cout << endl;
}

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int start, vector<int> &res) {
    // mark current vertex as visited
    visited[start] = true;

    res.push_back(start);

    // recursively visit the rest
    for (int i: adj[start]) 
        if (!visited[i]) 
           dfs(adj, visited, i, res);
}

vector<int> DFS(vector<vector<int>> &adj) {
    int len = adj.size();
    vector<bool> visited(len, false);
    vector<int> res;
    

    // traverse all vertices
    for (int i = 0;i < adj.size(); i ++)  
        // if not visited, perform DFS
        if (!visited[i]) 
            dfs(adj, visited, i, res);

    return res;
}

int main() {
    vector<vector<int>> adjl = {
        {1,2},
        {2,0},
        {0,3},
        {4,5},
        {}, // since we are including 4,5 nodes. we need empty arrays for those
        {}
    };
    
    vector<int> res = DFS(adjl);
    PrintVector(res);
}
