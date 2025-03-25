#include <bits/stdc++.h>
using namespace std;




int countWays(string &s) {
	// code here
	int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    // Initialisation : une seule lettre (T ou F)
    for (int i = 0; i < n; i += 2) {
        dp[i][i][1] = (s[i] == 'T');
        dp[i][i][0] = (s[i] == 'F');
    }

    // Remplissage de la table DP
    for (int len = 3; len <= n; len += 2) {  // On traite les sous-expressions de taille croissante
        for (int i = 0; i <= n - len; i += 2) {
            int j = i + len - 1;
            dp[i][j][0] = dp[i][j][1] = 0;

            // Parcourir les opérateurs entre i et j
            for (int k = i + 1; k < j; k += 2) {
                char op = s[k];
                int leftTrue = dp[i][k - 1][1], leftFalse = dp[i][k - 1][0];
                int rightTrue = dp[k + 1][j][1], rightFalse = dp[k + 1][j][0];

                if (op == '&') {
                    dp[i][j][1] += leftTrue * rightTrue;
                    dp[i][j][0] += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
                } 
                else if (op == '|') {
                    dp[i][j][1] += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                    dp[i][j][0] += leftFalse * rightFalse;
                } 
                else if (op == '^') {
                    dp[i][j][1] += leftTrue * rightFalse + leftFalse * rightTrue;
                    dp[i][j][0] += leftTrue * rightTrue + leftFalse * rightFalse;
                }
            }
        }
    }

    return dp[0][n - 1][1];
}