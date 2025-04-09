#include <iostream>
#include <vector>
using namespace std;

/************************************************************************************************************************
  * You are given weights and values of N items, put these items in a knapsack of capacity W
  * to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
  * In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values
  * and weights associated with N items respectively. Also given an integer W which represents knapsack capacity,
  * find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
  * You cannot break an item, either pick the complete item or dont pick it (0-1 property).
  * Expected Time Complexity: O(N*W).
  * Expected Auxiliary Space: O(N*W)
  ************************************************************************************************************************/
int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n + 1, vector<int> (W + 1, 0));
       
       for(int i = 1; i <= n; i++){
           for(int j = 1; j <= W; j++){
               if(wt[i - 1] <= j){
                   dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
               }else{
                   dp[i][j] = dp[i - 1][j];
               }
           }
       }
       
       return dp[n][W];
    }
