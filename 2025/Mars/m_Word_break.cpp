#include <bits/stdc++.h>
using namespace std;

/*****
 * 
 * 
 */

bool wordBreak(string &s, vector<string> &dictionary) {
	// code here
	int n = s.size();
	vector<bool> dp(n + 1, false);
	dp[0] = true;  

	unordered_set<string> dict(dictionary.begin(), dictionary.end()); 

	int max_len = 0;
	for (const string& word : dictionary) {
		max_len = max(max_len, (int)word.size());
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = max(0, i - max_len); j < i; ++j) {
			if (dp[j] && dict.count(s.substr(j, i - j))) {
				dp[i] = true;
				break;
			}
		}
	}

	return dp[n];
}