#include <bits/stdc++.h>
using namespace std;

/*****************************************************************************
 * Given a 2D array houses[][], consisting of n 2D coordinates {x, y}
 * where each coordinate represents the location of each house,
 * the task is to find the minimum cost to connect all the houses of the city.
 * 
 * The cost of connecting two houses is the Manhattan Distance between
 * the two points (xi, yi) and (xj, yj) i.e., |xi – xj| + |yi – yj|,
 * where |p| denotes the absolute value of p.
 *****************************************************************************/

class Solution {
	public:
	  struct Edge {
		  int u, v, weight;
	  };
	  
	  vector<int> parent, size;
	  
	  int find(int u){
		  if(parent[u] != u)
			  parent[u] = find(parent[u]);
		  return parent[u];
	  }
	  
	  void unionSets(int u, int v){
		  int rootU = find(u);
		  int rootV = find(v);
		  
		  if (rootU != rootV){
			  if (size[rootU] < size[rootV]){
				  swap(rootU, rootV);
			  }
			  parent[rootV] = rootU;
			  size[rootU] += size[rootV];
		  }
	  }
	  
	  int minCost(vector<vector<int>>& houses) {
		  // code here
		  vector<Edge> edges;
		  int n = houses.size();
		  
		  parent.resize(n);
		  size.resize(n);
		  for(int i = 0; i < n; i++){
			  parent[i] = i;
			  for(int j = i + 1; j < n; j++){
				  int dist = abs(houses[i][0] - houses[j][0]) +
							  abs(houses[i][1] - houses[j][1]);
				  edges.push_back({i, j, dist});
			  }
		  }
		  
		  sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
			  return a.weight < b.weight;
		  });
		  
		  int mstWeight = 0;
		  for(const auto& edge : edges){
			  int u = edge.u;
			  int v = edge.v;
			  int weight = edge.weight;
			  
			  if (find(u) != find(v)){
				  unionSets(u, v);
				  mstWeight += weight;
			  }
		  }
		  
		  return mstWeight;
	  }
  };