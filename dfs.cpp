#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;
    
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

void printDFS(const vector<vector<int>> &components) {
    cout << "DFS Traversal of Components:" << endl;
    for (const auto &component : components) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertex, edgeCount;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex >> edgeCount;
    
    vector<vector<int>> edges(edgeCount, vector<int>(2));
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edgeCount; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    vector<vector<int>> dfsOrder = depthFirstSearch(vertex, edgeCount, edges);
    printDFS(dfsOrder);
    
    return 0;
}