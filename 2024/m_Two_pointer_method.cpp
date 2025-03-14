#include <iostream>
using namespace std;

/****************************************************************************************
 * Given an array arr[] denoting heights of N towers and a positive integer K.
 * For each tower, you must perform exactly one of the following operations exactly once.
 *   Increase the height of the tower by K
 *   Decrease the height of the tower by K
 * Find out the minimum possible difference between the height of the shortest and
 * tallest towers after you have modified each tower.
 * You can find a slight modification of the problem here.
 * Expected Time Complexity: O(N*logN)
 * Expected Auxiliary Space: O(N)
 * 
 ****************************************************************************************/

int getMinDiff(int arr[], int n, int k) {
    // code here
    sort(arr,arr+n);
    int minDiff = arr[n - 1] - arr[0];
    
    int largest = arr[n - 1] - k;
    int smallest = arr[0] + k;
    int mi, ma;
    
    for(int i = 1; i < n; i++){
      mi=min(smallest, arr[i] - k);
      ma=max(largest, arr[i - 1] + k);
      if(mi < 0) continue;
      minDiff = min(minDiff, ma - mi);
    }
    
    return minDiff;
}
