#include <iostream>
using namespace std;

/**********************************************************
 * Given an array of size N containing only 0s, 1s, and 2s
 * sort the array in ascending order.
 * Expected Time Complexity: O(N)
 * Expected Auxiliary Space: O(1) 
***********************************************************/
void sort012(int a[], int n)
    {
        // code here
        int low = 0, mid = 0, high = n - 1;
        int tempVal;
        while(mid <= high){
            if(a[mid] == 0){
                tempVal = a[mid];
                a[mid] = a[low];
                a[low] = tempVal;
                low++;
                mid++;
            }else if(a[mid] == 1){
                mid++;
            }else{
                tempVal = a[mid];
                a[mid] = a[high];
                a[high] = tempVal;
                high--;
            }
        }
    }
