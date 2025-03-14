#include <iostream>
using namespace std;

/***************************************************
  Given an array of size N-1 such that
  it only contains distinct integers
  in the range of 1 to N. Find the missing element.
  **************************************************/
int missingNumber(vector<int>& array, int n) {
  int total = n*(n + 1) / 2;
  for(int i = 0; i < n - 1; i++){
    total -= array[i];
  }
  return total;
}
