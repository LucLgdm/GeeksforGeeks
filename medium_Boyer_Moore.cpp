#include <iostream>
using namespace std;

/*************************************************************************
 * Given an array A of N elements. Find the majority element in the array.
 * A majority element in an array A of size N is an element that appears
 * strictly more than N/2 times in the array.
 * Expected Time Complexity: O(N).
 * Expected Auxiliary Space: O(1).
 *************************************************************************/

int majorityElement(int a[], int size){
  // your code here
  int value = -1;
  int count = 0;
  
  for(int i = 0; i < size; i++){
      if(count == 0){
          value = a[i];
          count = 1;
      }else if(a[i] == value){
          count++;
      }else{
          count--;
      }
  }
  
  count = 0;
  for(int i = 0; i < size; i++){
      if(a[i] == value){
          count++;
      }
  }
  
  if(count > size/2){
      return value;
  }else{
      return -1;
  }
}
