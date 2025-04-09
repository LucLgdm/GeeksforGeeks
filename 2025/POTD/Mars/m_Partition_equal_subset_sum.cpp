#include <bits/stdc++.h>
using namespace std;

/****************************************************************************
 * Given an array arr[], determine if it can be partitioned into two subsets
 * such that the sum of elements in both parts is the same.
 * 
 * Note: Each element must be in exactly one subset.
 *****************************************************************************/

 bool equalPartition(vector<int>& arr) {
	// code here
	int sum = 0;
    int n = arr.size();

	for(int i = 0; i < n; i++){
		sum += arr[i];
	}
	if (sum % 2 == 1) return false;

	int target = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

	for(int i = 0; i < n; i++) dp[i][0] = true;

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= target; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= arr[i - 1])
				dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
		}
	}
	return dp[n][target];
}


bool equalPartition(vector<int>& arr) {
    int sum = 0, n = arr.size();
    for (int num : arr) sum += num;

    if (sum % 2 == 1) return false;

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : arr) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}
