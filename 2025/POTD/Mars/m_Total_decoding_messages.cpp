#include <bits/stdc++.h>
using namespace std;

/************************************************************************************************************
 *  A message containing letters A-Z is being encoded to numbers using the following mapping:
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * You are given a string digits. You have to determine the total number of ways that message can be decoded.
 *************************************************************************************************************/

int countWays(string &digits) {
	// Code here
	if(digits.empty() || digits[0] == '0') return 0;

	int n = digits.size();
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;

	for(int i = 2; i < n + 1; i++){
		if(digits[i - 1] != '0')
			dp[i] += dp[i - 1];
		int twodigit = stoi(digits.substr(i - 2, 2));
		if (twodigit >= 10 && twodigit <= 26)
			dp[i] += dp[i - 2];
	}

	return dp[n];
}