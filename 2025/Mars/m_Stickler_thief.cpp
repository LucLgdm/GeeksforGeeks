#include <bits/stdc++.h>
using namespace std;

/***************************************************************************************
 * Stickler the thief wants to loot money from the houses arranged in a line.
 * He cannot loot two consecutive houses and aims to maximize his total loot.
 * Given an array, arr[] where arr[i] represents the amount of money in the i-th house.
 * Determine the maximum amount he can loot.
 ***************************************************************************************/

 int findMaxSum(vector<int>& arr) {
	// code here
	int n = arr.size();
	if (n == 0) return 0;
	if (n == 1) return arr[0];

	vector<int> dp(n + 1, 0);
	dp[1] = arr[0];

	for(int i = 2; i < n + 1; i++){
		dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);
	}
	return dp[n];
}
