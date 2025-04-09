#include <bits::stdc++.h>
using namespace std;

/*************************************************************************************************
 * Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid)
 * consisting of 'W's (Water) and 'L's (Land). Find the number of islands.
 * 
 * Note: An island is either surrounded by water or the boundary
 * of a grid and is formed by connecting adjacent lands horizontally or vertically
 * or diagonally i.e., in all 8 directions.
 *************************************************************************************************/

int countIslands(vector<vector<char>>& grid) {
	// Code here
	int n = grid.size();
	int m = grid[0].size();
	int count = 0;

	if(n == 0 || m == 0) return count;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 'L'){
				count++;
				dfs(grid, i, j, n, m);
			}
		}
	}
	return count;
}

void dfs(vector<vector<char>>&grid, int i, int j, int n, int m){
	grid[i][j] = 'W';
	int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	for(int k = 0; k < 8; k++){
		int nx = i + dx[k];
		int ny = j + dy[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 'L'){
			dfs(grid, nx, ny, n, m);
		}
	}
}