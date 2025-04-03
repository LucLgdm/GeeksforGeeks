#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 * Given a connected undirected graph containing V vertices represented
 * by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i.
 * Perform a Breadth First Search (BFS) traversal starting from vertex 0,
 * visiting vertices from left to right as per the given adjacency list,
 * and return a list containing the BFS traversal of the graph.
 * Note: Do traverse in the same order as they are in the given adjacency list.
 *************************************************************************************************************/


vector<int> bfs(vector<vector<int>>&adj) {
	// Code here
	vector<int> result;
	vector<bool> visited(adj.size(), false);
	queue<int> q;
	
	q.push(0);
	visited[0] = true;

	while(!q.empty()){
		int node = q.front();
		q.pop();
		result.push_back(node);

		for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
		}
	}

	return result;
}