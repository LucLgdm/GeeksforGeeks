#include <iostream>
using namespace std;

#define ll long long

/**********************************************************************
 * Given an array of N positive integers  Arr1, Arr2 ............ Arrn.
 * The value of each contiguous subarray of given array is the maximum
 * element present in that subarray. The task is to return the number
 * of subarrays having value strictly greater than K.
 * Expected Time Complexity: O(N)
 * Expected Auxiliary Space: O(1)
************************************************************************/
	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    int sum = 0;
	    ll count = 0;
	    int down = 0;
	    int up;
    
	    for (up = 0; up < n; up++){
	        sum += arr[up];
	        while(sum > k && down <= up){
	            count += n - up;
	            sum -= arr[down];
	            down++;
	        }
	    }
	    return count;
	}
