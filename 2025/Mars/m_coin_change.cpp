#include <vector>
#include <iostream>
using namespace std;

/***************************************************************************************
 * Given an integer array coins[ ] representing different denominations of currency
 * and an integer sum, find the number of ways you can make sum by using different
 * combinations from coins[ ].
 * Note: Assume that you have an infinite supply of each type of coin.
 * Therefore, you can use any coin as many times as you want.
 * Answers are guaranteed to fit into a 32-bit integer. 
 ***************************************************************************************/

int count(vector<int>& coins, int sum) {
	// code here.
	int n = coins.size();
	vector<int> dp(sum + 1, 0);
	dp[0] = 1;

	for(int coin : coins){
		for(int j = coin; j <= sum; j++)
			dp[j] += dp[j - coin];
	}
	return dp[sum];
}

int count(vector<int>& coins, int sum) {
	// code here
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (int j = 0; j <= sum; j++) {
        if (j % coins[0] == 0)
            dp[0][j] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i])
                dp[i][j] += dp[i][j - coins[i]];
        }
    }
    return dp[n - 1][sum];
}