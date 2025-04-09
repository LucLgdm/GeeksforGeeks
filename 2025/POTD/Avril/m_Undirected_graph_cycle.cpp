#include <bits/stdc++.h>
using namespace std;

/************************************************************************************************
 * Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][],
 * where each entry edges[i] = [u, v] denotes an edge between vertices u and v,
 * determine whether the graph contains a cycle or not.
 ************************************************************************************************/

bool isCycle(int V, vector<vector<int>>& edges) {
	// Code here
	vector<vector<int>> adj(V);
	for (auto it : edges) {
		adj[it[0]].push_back(it[1]);
		adj[it[1]].push_back(it[0]);
	}

	vector<bool> visited(V, false);

	for(int i = 0; i < V; i++){
		if(!visited[i]){
			queue<pair<int, int>> q;
			q.push({i, -1});
			visited[i] = true;

			while(!q.empty()){
				int node = q.front().first;
				int parent = q.front().second;
				q.pop();
				for(auto neighbor : adj[node]){
					if (!visited[neighbor]){
						visited[neighbor] = true;
						q.push({neighbor, node});
					}else if (parent != neighbor){
						return true;
					}
				}
			}
		}
		return false;
	}
}
