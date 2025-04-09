#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************************
 * Given a matrix mat[][] of dimension n * m where each cell in the matrix can have values 0, 1 or 2
 * which has the following meaning:
 * 0 : Empty cell
 * 1 : Cell have fresh oranges
 * 2 : Cell have rotten oranges
 * 
 * We have to determine what is the earliest time after which all the oranges are rotten.
 * A rotten orange at index (i, j) can rot other fresh orange
 * at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.
 * 
 * Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.
 *************************************************************************************************************/

int orangesRotting(vector<vector<int>>& mat) {
	// Code here
	int n = mat.size();
	int m = mat[0].size();
	int fresh = 0;
	queue<pair<int, int>> q;
	int time = 0;

	vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1) {
				fresh++;
			} else if (mat[i][j] == 2) {
				q.push({i, j});
			}
		}
	}
	
	if (fresh == 0) return 0;

	while(!q.empty()){
		int size = q.size();
		bool rotten = false;

		for(int i = 0; i < size; i++){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for(const vector<int>& dir : directions){
				int nx = x + dir[0];
				int ny = y + dir[1];

				if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1){
					mat[nx][ny] = 2;
					q.push({nx, ny});
					fresh--;
					rotten = true;
				}
			}
		}
		if (rotten) time++;
	}
	return (fresh == 0) ? time : -1;
}

int main() {
    // Exemple de matrice
    vector<vector<int>> mat = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}
    };

    // Appel de la fonction et affichage du résultat
    int result = orangesRotting(mat);
    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}