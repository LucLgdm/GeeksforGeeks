#include <iostream>
using namespace std;

/***************************************************************************
* Given a non-negative integer N. The task is to check if N is a power of 2.
* More formally, check if N can be expressed as 2x for some integer x.
* Return true if N is power of 2 else return false.
* Example :
* Input: N = 8, Output: YES
* Explanation : 8 is equal to 2 raised to 3 (23 = 8).
* Expected Time Complexity:O(log N).
* Expected Auxiliary Space:O(1).
*****************************************************************************/

bool isPowerofTwo(long long n){
  if(n == 0) return false;
  while(n > 1){
      if(n%2 != 0) return false;
      n = n/2;
  }
  return true;
}
