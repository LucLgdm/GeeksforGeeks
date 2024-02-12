#include <iostream>
using namespace std;

/********************************************************************
* Given a number N. Find the minimum number of operations required 
* to reach N starting from 0. You have 2 operations available:
*   Double the number
*   Add one to the number
*
* Example
* Input: N = 8, Output: 4
* Explanation: 
* 0 + 1 = 1 --> 1 + 1 = 2 --> 2 * 2 = 4 --> 4 * 2 = 8.
* Expected Time Complexity: O(LogN)
* Expected Auxiliary Space: O(1)
*********************************************************************/

int minOperation(int n){
  //code here.
  if(n == 1){
    return 1;
  }else if(n == 2){
    return 2;
  }else if(n%2 == 0){
    return minOperation(n/2) + 1;
  }else{
    return minOperation(n - 1) + 1
  }
}
