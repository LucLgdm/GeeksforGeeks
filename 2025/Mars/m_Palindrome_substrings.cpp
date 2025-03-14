/********************************************************************************
 * Given a string s, count all palindromic sub-strings present in the string.
 * The length of the palindromic sub-string must be greater than or equal to 2.
 * ******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int countPS(string &s) {
	// code here
	int n = s.length(), count = 0;
	vector<vector<bool>> dp(n, vector<bool>(n, false));

	for(int i = 0; i < n; i++){
		dp[i][i] = true;
	}
	// On regarde pour des sous chaines de taille 2 a n
	for(int length = 2; length <= n; length++){
		for(int i = 0; i <= n - length; i++){
			// j est la fin de la sous-chaine de longeur length
			int j = i + length - 1;
			if (s[i] == s[j] && (length == 2 || dp[i + 1][j - 1])){
				dp[i][j] = true;
				if (length >= 2)
					count++;
			}
		}
	}
	return count;
}

int main(int argc, char **argv){
	string s1 = argv[1];
	int res = countPS(s1);
	printf("Number of palindrome = %i\n", res);
	return 0;
}
