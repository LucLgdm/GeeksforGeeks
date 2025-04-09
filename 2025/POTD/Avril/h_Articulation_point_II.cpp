#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************
 * You are given an undirected graph with V vertices and E edges.
 * The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v]
 * indicates an undirected edge between vertices u and v.
 * Your task is to return all the articulation points (or cut vertices) in the graph.
 * An articulation point is a vertex whose removal, along with all its connected edges,
 * increases the number of connected components in the graph.
 * 
 * Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
 * If no such point exists, return {-1}.
 *************************************************************************************************/


vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
	// Code here
	vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<int> parent(V, -1); 
    vector<bool> ap(V, false); 
    int time = 0;

    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = time++;
        int children = 0;

        for (int v : adj[u]) {
            if (disc[v] == -1) {
                children++;
                parent[v] = u;
                dfs(v);

                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1) {
                    ap[u] = true;
                }

                if (parent[u] != -1 && low[v] >= disc[u]) {
                    ap[u] = true;
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    };

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            dfs(i);
        }
    }

    vector<int> result;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            result.push_back(i);
        }
    }

    if (result.empty()) {
        return {-1};
    }
    return result;
}