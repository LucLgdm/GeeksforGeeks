#include <iostream>
#include <vector>
using namespace std;

/************************************************************************************
 * Given an array arr[] of N non-negative integers representing the height of blocks.
 * If width of each block is 1, compute how much water can be trapped
 * between the blocks during the rainy season. 
 * Input: N = 6, arr[] = {3,0,0,2,0,4}; Output: 10
 * Expected Time Complexity: O(N)
 * Expected Auxiliary Space: O(N)
 ************************************************************************************/

long long trappingWater(int arr[], int n){
        // code here
        long long totalWater = 0;
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        
        maxLeft[0] = arr[0], maxRight[n - 1] = arr[n - 1];
        
        for(int i = 1; i < n - 1; i++){
            maxLeft[i] = max(maxLeft[i - 1], arr[i]);
        }
        for(int i = n - 2; i > 0; i--){
            maxRight[i] = max(maxRight[i + 1], arr[i]);
        }
        
        for(int i = 0; i < n; i++){
            int minHeight = min(maxLeft[i], maxRight[i]);
            totalWater += max(0, minHeight - arr[i]);
        }
        return totalWater;
    }
