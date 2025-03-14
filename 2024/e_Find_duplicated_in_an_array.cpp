#include <iostream>
using namespace std;

/*******************************************************************************
* Given an array a of size N which contains elements from 0 to N-1,
* you need to find all the elements occurring more than once in the given array.
* Return the answer in ascending order.
* If no such element is found, return list containing [-1]. 
* Note: The extra space is only for the array to be returned.
* Try and perform all operations within the provided array.
* Example :
* Input : N = 5, a[] = {2,3,1,2,3}
* Output: 2 3
* Explanation : 2 and 3 occur more than once in the given array.
* Expected Time Complexity: O(n).
* Expected Auxiliary Space: O(n).
*********************************************************************************/
vector<int> duplicates(long long arr[], int n) {
  // code here
  vector<int> result;
  for (int i = 0; i < n; i++) {
      int index = arr[i] % n;
      arr[index] += n;
  }

  for (int i = 0; i < n; i++) {
      if (arr[i] / n > 1) {
          result.push_back(i);
      }
  }

  if (result.empty()) {
      result.push_back(-1);
  }

  sort(result.begin(), result.end());
  return result;
}
