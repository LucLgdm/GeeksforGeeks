#include <bits/stdc++.h>
using namespace std;

/*****************************************************************************************
 * You are given an array coins[], where each element represents a coin
 * of a different denomination, and a target value sum.
 * You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.
 * Your task is to determine the minimum number of coins needed to obtain the target sum.
 * If it is not possible to form the sum using the given coins, return -1
 ******************************************************************************************/

 int minCoins(vector<int> &coins, int sum) {
	// code here
	vector<int> dp(sum + 1, INT_MAX);

	dp[0] = 0;
	for(int j = 1; j < sum + 1; j++){
		for(int coin : coins){
			if ( j >= coin && dp[j - coin] != INT_MAX)
				dp[j] = min(dp[j], 1 + dp[j - coin]);
		}
	}
	if (dp[sum] == INT_MAX)
		return -1;
	else
		return dp[sum];
}