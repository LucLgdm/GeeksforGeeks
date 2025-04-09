#include <bits/stdc++.h>
using namespace std;


/***************************************************************************************************
 * You are given an array arr[] which represents houses arranged in a circle,
 * where each house has a certain value.
 * A thief aims to maximize the total stolen value without robbing two adjacent houses
 * Determine the maximum amount the thief can steal.
 * 
 * Note: Since the houses are in a circle, the first and last houses are also considered adjacent.
 ***************************************************************************************************/

 int rob_linear(vector<int>& arr, int start, int end) {
    if (start > end) return 0;
    
    int prev2 = 0, prev1 = 0;
    
    for (int i = start; i < end + 1; i++) {
        int take = arr[i] + prev2;
        int skip = prev1;
        int curr = max(take, skip);
        
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int maxValue(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0];

    // Cas 1 : Voler les maisons de 0 à n-2
    int loot_1 = rob_linear(arr, 0, n - 2);
    
    // Cas 2 : Voler les maisons de 1 à n-1
    int loot_2 = rob_linear(arr, 1, n - 1);

    return max(loot_1, loot_2);
}

