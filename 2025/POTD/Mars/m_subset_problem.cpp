#include <bits/stdc++.h>
using namespace std;

/*************************************************************************
 * Given an array of positive integers arr[] and a value sum,
 * determine if there is a subset of arr[] with sum equal to given sum. 
 * Examples:
 * 
 * Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
 * Output: true 
 * Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
 **************************************************************************/

bool isSubsetSum(vector<int>& arr, int sum) {
	// code here
	int n = arr.size();
	vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

	for(int i = 0; i <= n; i++){
		dp[i][0] = true;
	}
	for(int i= 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			dp[i][j] = dp[i - 1][j];
			if(j - arr[i - 1] >= 0)
				dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
		}
	}
	return dp[n][sum];
}