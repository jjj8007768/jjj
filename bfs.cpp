#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <vector>
using namespace std;

void preparedAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        
        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    preparedAdjList(adjList, edges);
    
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

void printBFS(const vector<int> &order) {
    cout << "BFS Traversal Order: ";
    for (int node : order) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int vertex, edgeCount;
    cout << "Enter number of vertices and edges: ";
    cin >> vertex >> edgeCount;
    
    vector<pair<int, int>> edges;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edgeCount; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    
    vector<int> bfsOrder = BFS(vertex, edges);
    printBFS(bfsOrder);
    
    return 0;
}