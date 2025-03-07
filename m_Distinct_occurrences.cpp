#include <iostream>
#include <vector>
using namespace std;

/***************************************************************
 * Given two strings s and t of length n and m respectively.
 * Find the count of distinct occurrences of t in s 
 * as a sub-sequence modulo 109 + 7.
 * Expected Time Complexity: O(n*m).
 * Expected Auxiliary Space: O(n*m).
 * Example :
 * Input: s = "banana" , t = "ban"; Output: 3
 * Explanation: There are 3 sub-sequences:[ban], [ba n], [b an].
****************************************************************/

/* I use a dynaminc programmation, it can be optimized by using a 1D array instead of a 2D array */

int subsequenceCount(string s, string t)
    {
      //Your code here
      int n = s.length(), m = t.length();
      const int mod = 1000000007;
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
      
      // t is empty
      for(int i = 0; i <= n; i++){
          dp[i][0] = 1;
      }
      
      for(int i = 1; i <= n ; i++){
          for(int j = 1; j <= m; j++){
              dp[i][j] = dp[i - 1][j];
              if(s[i - 1] == t[j - 1]){
                  dp[i][j] += dp[i - 1][j - 1];
              }
              dp[i][j] %= mod;
          }
      }
      return dp[n][m];
    }
