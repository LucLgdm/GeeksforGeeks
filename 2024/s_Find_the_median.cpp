#include <iostream>
using namespace std;

/*********************************************
* Given an array arr[] of N integers
* calculate the median.
* NOTE: Return the floor value of the median.
* Expected Time Complexity: O(n * log(n))
* Expected Space Complexity: O(1)
**********************************************/

int find_median(vector<int> v){
  int n = v.size();
  for(int i = v.size(); i > 0; i--){
      for(int j = 0; j < i - 1; j++){
          if (v[j + 1] < v[j]){
              int c = v[j + 1];
              v[j + 1] = v[j];
              v[j] = c;
          }
      }
  }
  // The vector v is sorted
  if(n%2 == 1){
      return v[n/2];
  }else{
      return (v[n/2 - 1] + v[n/2])/2;
  }
}
