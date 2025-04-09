#include <bits/stdc++.h>
using namespace std;

/*********************************************************************************
 * Given an array arr[] which represents the dimensions of a sequence of matrices
 * where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1,
 * find the most efficient way to multiply these matrices together.
 * The efficient way is the one that involves the least number of multiplications.
 **********************************************************************************/

int matrixMultiplication(vector<int> &arr) {
	// code here
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for(int len = 2; len < n; len++){
		for(int i = 1; i < n - len + 1; i++){
			int j = i + len - 1;
			dp[i][j] = INT_MAX;

			for(int k = i ; k < j; k++){
				int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
			}
		}
	}
	return dp[1][n - 1];
}


// dp[i][j] représente le coût minimal pour multiplier les matrices de M_i à M_j.

// On essaie toutes les séparations possibles entre M_i et M_j :
// dp[i][j]=min⁡i≤k<j(dp[i][k]+dp[k+1][j]+(cout de la multiplication))
// dp[i][j]=i≤k<jmin​(dp[i][k]+dp[k+1][j]+(cout de la multiplication))

// où le coût de la multiplication est donné par :
// arr[i−1]×arr[k]×arr[j]
// arr[i−1]×arr[k]×arr[j]