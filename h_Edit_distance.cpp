/*************************************************************************************************************
 * Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
 * The possible operations are permitted:
 * 
 * 	Insert a character at any position of the string.
 * 	Remove any character from the string.
 *	Replace any character from the string with any other character.
****************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int editDistance(string& s1, string& s2) {
	// code here
	int n = s1.length(), m = s2.length();
	int dp[n + 1][m + 1];

	for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j++){
			// Si les caracteres de s1 et s2 sont egaux
			if (s1[i - 1] == s2[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			// # operations possibles : suppression de s1, insertion dans s1, remplacement dans s1
			}else{
				dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
			}
		}
	}
	return dp[n][m];
}

int main(int argc, char **argv){
	string s1 = argv[1];
	string s2 = argv[2];
	int res = editDistance(s1, s2);
	printf("Distance = %i\n", res);
	return 0;
}
