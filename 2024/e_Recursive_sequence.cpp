#include <iostream>
using namespace std;


/********************************************************************************
* A function F is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... upto n terms.
* Given an integer n, determine the F(n).
* Note: As the answer can be very large, return the answer modulo 109+7.
*********************************************************************************/

long long sequence(int n){
  // code here
  int modulo = 1000000007;
  if (n == 1){
    return 1;
  }else{
    long long k = 1;
    for(int i = n*(n-1)/2 + 1; i < n*(n-1)/2 + n + 1; i++){
      k *= i;
      k = k % modulo;
    }        
    return (sequence(n - 1) + k)%modulo;
  }
}
