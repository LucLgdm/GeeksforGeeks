#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 * Given a connected undirected graph containing V vertices represented
 * by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i.
 * Perform a Depth First Search (DFS) traversal starting from vertex 0,
 * visiting vertices from left to right as per the given adjacency list,
 * and return a list containing the DFS traversal of the graph.
 * Note: Do traverse in the same order as they are in the given adjacency list.
 *************************************************************************************************************/
vector<int> dfs(int node, vector<vector<int>>&adj, vector<bool>& visited, vector<int>& result) {
	visited[node] = true;
	result.push_back(node);

	for (int i = 0; i < adj[node].size(); i++) {
		if (!visited[adj[node][i]]) {
			dfs(adj[node][i], adj, visited, result);
		}
	}
	return result;
}

vector<int> dfs(vector<vector<int>>& adj) {
	// Code here
	vector<int> result;
	vector<bool> visited(adj.size(), false);

	dfs(0, adj, visited, result);
	return result;
}