#include <bits/stdc++.h>
using namespace std;

/********************************************************************************************************
 * In daily share trading, a trader buys shares and sells them on the same day.
 * If the trader is allowed to make at most 2 transactions in a day,
 * find out the maximum profit that a share trader could have made.
 * You are given an array prices[] representing stock prices throughout the day.
 * Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).
 * Input: prices[] = [10, 22, 5, 75, 65, 80]
 * Output: 87
 * Explanation: 
 * Trader will buy at 10 and sells at 22. 
 * Profit earned in 1st transaction = 22 - 10 = 12. 
 * Then he buys at 5 and sell at 80. 
 * Profit earned in 2nd transaction = 80 - 5 = 75. 
 * Total profit earned = 12 + 75 = 87. 
 *********************************************************************************************************/

 int maxProfit(vector<int> &prices) {
	// code here
	if (prices.empty()) return 0;

	int first_buy = INT_MAX, first_profit = 0;
	int second_buy = INT_MAX, second_profit = 0;

	for(int price : prices){
		first_buy = min(first_buy, price);
		first_profit = max(first_profit, price - first_buy);
		second_buy = min(second_buy, price - first_profit);
		second_profit = max(second_profit, price - second_buy);
	}
	return second_profit;
}
