#include <iostream>
#include <vector>
using namespace std;

/**********************************************************************************************
* Given an array Arr of N positive integers.
* Your task is to find the elements whose value is equal to
* that of its index value ( Consider 1-based indexing ).
* Note: There can be more than one element in the array which have the same value as its index.
* You need to include every such element's index. Follows 1-based indexing of the array.
* Example :
* Input: N = 5, Arr[] = {15, 2, 45, 12, 7}
* Output: 2
* Explanation: Only Arr[2] = 2 exists here.
* Expected Time Complexity: O(N)
* Expected Auxiliary Space: O(1)
***********************************************************************************************/  
vector<int> valueEqualToIndex(int arr[], int n) {
  // code here
  vector<int> solution;
  for(int i = 0; i < n; i++){
      if(arr[i] == i + 1){
          solution.push_back(i + 1);
      }
  }
  return solution;
}
