#include <iostream>
#include <vector>
using namespace std;

/********************************************************************************************************
 * In daily share trading, a buyer buys shares in the morning and sells them on the same day.
 * If the trader is allowed to make at most 2 transactions in a day,
 * the second transaction can only start after the first one is complete (buy->sell->buy->sell).
 * The stock prices throughout the day are represented in the form of an array of prices.
 * Given an array price of size n, find out the maximum profit that a share trader could have made.
 * Expected Time Complexity: O(n)
 * Expected Space Complexity: O(n)
 * Example : 
 * Input: n = 7, prices[] = {2,30,15,10,8,25,80}; Output: 100
 * Explanation: Trader earns 100 as sum of 28 and 72 Buy at price 2, sell at 30, Buy at 8 and sell at 80.
 ********************************************************************************************************/

int maxProfit(vector<int>&price){
            //Write your code here..
            int n = price.size();
            if(n < 2) return 0;
            
            vector<int> profit1(n, 0);
            vector<int> profit2(n, 0);
            
            // Calculation of the maximal profit possible
            int minPrice = price[0];
            for(int i = 1; i < n; i++){
                profit1[i] = max(profit1[i - 1], price[i] - minPrice);
                minPrice = min(minPrice, price[i]);
            }
            
            // Calculation of the possible profit from every day
            int maxPrice = price[n - 1];
            for(int i = n - 2; i >= 0; i--){
                profit2[i] = max(profit2[i + 1], maxPrice - price[i]);
                maxPrice = max(maxPrice, price[i]);
            }
            
            // Fiding the optimal day to realise 2 transactions
            int maxProfit = 0;
            for(int i = 0; i < n; i++){
                maxProfit = max(maxProfit, profit1[i] + profit2[i]);
            }
            
            return maxProfit;
        }
