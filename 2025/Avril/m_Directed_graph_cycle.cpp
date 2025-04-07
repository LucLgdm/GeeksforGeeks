#include <bits/stdc++.h>
using namespace std;

/*******************************************************************************
 * Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
 * check whether it contains any cycle or not.
 * The graph is represented as a 2D vector edges[][],
 * where each entry edges[i] = [u, v] denotes an edge from verticex u to v.
 *******************************************************************************/

bool isCyclic(int V, vector<vector<int>> &edges) {
	// code here
	vector<bool> visited(V, false);
	vector<bool> recStack(V, false);

	vector<vector<int>> adj(V);
	for (auto it : edges) {
		adj[it[0]].push_back(it[1]);
	}
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			if (dfs(i, visited, recStack, adj)) {
				return true;
			}
		}
	}
	return false;
}

bool dfs(int node, vector<bool> &visited, vector<bool> &recStack, vector<vector<int>> &adj) {
	visited[node] = true;
	recStack[node] = true;

	for (auto neighbor : adj[node]) {
		if (!visited[neighbor]) {
			if (dfs(neighbor, visited, recStack, adj)) {
				return true;
			}
		} else if (recStack[neighbor]) {
			return true;
		}
	}

	recStack[node] = false;
	return false;
}