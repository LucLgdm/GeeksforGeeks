#include <bits/stdc++.h>
using namespace std;

/***************************************************************************************
 * In the stock market, a person buys a stock and sells it on some future date.
 * You are given an array prices[] representing stock prices on different days
 * and a positive integer k, find out the maximum profit a person can make
 * in at-most k transactions.
 * 
 * A transaction consists of buying and subsequently selling a stock
 * and new transaction can start only when the previous transaction has been completed.
 ***************************************************************************************/

int maxProfit(vector<int>& prices, int k) {
	// code here
	int n = prices.size();
	if(n == 0) return 0;

	/*Greedy approch in case we have unlimited transaction possible*/
	if (k >= n / 2){
		int profit = 0;
		for(int i = 1; i < n; i++){
			if (prices[i] > prices[i - 1])
				profit += prices[i] - prices[i - 1];
		}
		return profit;
	}
	/*Dynamic programming in normal case*/
	vector<vector<int>> dp(k + 1, vector<int>(n, 0));
	for(int i = 1; i <= k; i++){
		int maxDiff = -prices[0];
		for(int j = 1; j < n; j++){
			dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
			maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
		}
	}
	return dp[k][n - 1];
}