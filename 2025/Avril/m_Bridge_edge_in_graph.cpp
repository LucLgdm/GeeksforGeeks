#include <bits/stdc++.h>
using namespace std;

/*****************************************************************************************************
 * Given an undirected graph with V vertices numbered from 0 to V-1 and E edges,
 * represented by 2d array edges[][], where edges[i]=[u,v] represents the edge between
 * the vertices u and v. Determine whether a specific edge between two vertices (c, d) is a bridge.
 * 
 * Note:
 * 
 * An edge is called a bridge if removing it increases the number of connected components of the graph.
 * if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.

 *****************************************************************************************************/


bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
	// Code here
	vector<vector<int>> adj(V);
	for (auto it : edges) {
		adj[it[0]].push_back(it[1]);
		adj[it[1]].push_back(it[0]);
	}

	adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
	adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());

	vector<int> visited(V, 0);
	queue<int> q;

	q.push(c);
	visited[c] = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto it : adj[node]){
			if(!visited[it]){
				visited[it] = 1;
				q.push(it);
			}
		}
	}
	adj[c].push_back(d);
	adj[d].push_back(c);

	return !visited[d];
}