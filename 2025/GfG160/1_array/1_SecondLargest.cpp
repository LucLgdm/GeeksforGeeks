#include <bits/stdc++.h>
using namespace std;


int getSecondLargest(vector<int> &arr) {
	// code here
	int first = INT_MIN, second = INT_MIN;
	int n = arr.size();
	
	for(int i = 0; i < n; i++){
		if (arr[i] > first){
			second = first;
			first = arr[i];
		}
		if (arr[i] > second && arr[i] != first){
			second = arr[i];
		}
	}

	if (second < 0)
		return -1;
	else
		return second;
}

int main() {
	vector<int> arr = {10, 10, 10, 10};
	cout << getSecondLargest(arr) << endl;
	return 0;
}