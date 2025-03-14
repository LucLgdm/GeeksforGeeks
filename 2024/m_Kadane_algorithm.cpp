#include <iostream>
using namespace std;

/**************************************************************
* Given an array Arr[] of N integers.
* Find the contiguous sub-array(containing at least one number)
* which has the maximum sum and return its sum.
* Expected Time Complexity: O(N)
* Expected Auxiliary Space: O(1)
***************************************************************/

long long maxSubarraySum(int arr[], int n){
  
  // Your code here
  long long maxGlobal = arr[0];
  long long maxCurrent = arr[0];
  
  for(int i = 1; i < n; i++){
      maxCurrent = max(maxCurrent + arr[i], (long long)arr[i]);
      maxGlobal = max(maxCurrent, maxGlobal);
  }
  
  return maxGlobal;
  
}
