#include <bits/stdc++.h>
#include <queue>
using namespace std;
//Connected Graph
vector <int> BFS(vector <vector<int>> &adj) {
	int v = adj.size(), s = 0;
	vector <int> res;
	queue <int> q;
	vector <bool> visited(v, false);
	visited[s] = true;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for (int x : adj[cur]) {
			if (!visited[x]) {
				visited[x] = true;
				q.push(x);
			}
		}
	}
	return res;
}

int main() {
	vector <vector <int>> adj = {{1,2},{0,2,3},{0,4},{1,4},{2,3}};
	vector <int> ans = BFS(adj);
	for (auto i : ans) 
		cout << i << " ";
	return 0;
}