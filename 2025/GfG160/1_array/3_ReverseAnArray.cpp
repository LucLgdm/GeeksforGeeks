#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr) {
    // code here
    int tmp, low = 0, high = arr.size() - 1;
    
    while(low <= high){
        tmp = arr[low];
        arr[low] = arr[high];
        arr[high] = tmp;
        low++;
        high--;
    }
}


int main(){
	vector<int> arr = {1, 2, 3, 4, 5};
	reverseArray(arr);
	for(int num : arr)
		cout << num << " ";
	return 0;
}
