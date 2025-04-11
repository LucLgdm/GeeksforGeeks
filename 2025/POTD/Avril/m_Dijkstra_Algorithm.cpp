#include <bits/stdc++.h>
using namespace std;

/******************************************************************************************
 * Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges,
 * represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge
 * between the nodes u and v having w edge weight.
 * You have to find the shortest distance of all the vertices from the source vertex src,
 * and return an array of integers where the ith element denotes the shortest distance
 * between ith node and source vertex src.
 * 
 * Note: The Graph is connected and doesn't contain any negative weight edge.
 ******************************************************************************************/

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
	// Code here
	vector<vector<pair<int, int>>> adj(V);
	for (auto &edge : edges) {
		int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
	}

	vector<int> dist(V, INT_MAX);
	dist[src] = 0;
	/* paire de distance, sommet
	 * les paires sont stackees dans des vecteurs
	 * transforme la queue en min-heap pour prendre l'element le plus petit */
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, src});
	while (!pq.empty()){
		int d = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for(auto &it : adj[node]){
			int v = it.first;
			int w = it.second;
			if (d + w < dist[v]){
				dist[v] = d + w;
				pq.push({dist[v], v});
			}
		}
	}
	return dist;
}