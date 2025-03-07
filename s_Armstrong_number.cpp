#include <iostream>
using namespace std;

/********************************************************************************************************
*For a given 3 digit number, find whether it is armstrong number or not.
* An Armstrong number of three digits is a number such that the sum of the cubes
* of its digits is equal to the number itself. Return "Yes" if it is a armstrong number else return "No".
* NOTE: 371 is an Armstrong number since 33 + 73 + 13 = 371
* Example :
* Input: N = 153, Output: "Yes"
* Explanation: 153 is an Armstrong number since 1^3 + 5^3 + 3^3 = 153.
* Hence answer is "Yes".
* Expected Time Complexity: O(1)
* Expected Auxiliary Space: O(1)
**************************************************************/

string armstrongNumber(int n){
    int n_copie = n;
    int sum = 0;
    while(n > 0){
        sum += (n%10) * (n%10) * (n%10);
        n -= n%10;
        n /= 10;
    }
    
    if (sum == n_copie){
        return "Yes";
    }else{
        return "No";
    }
}
