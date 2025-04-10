#include <bits/stdc++.h>
using namespace std;


void pushZerosToEnd(vector<int>& arr) {
        // code here
        int insert = 0;
        
        for(int num : arr){
            if (num != 0){
                arr[insert++] = num;
            }
        }
        
        while(insert < arr.size())
            arr[insert++] = 0;
}


int main(){
	vector<int> arr = {1, 45, 3, 6, 0, 5646, 0, 64, 0, 0, 4, 2, 5, 2};
	for (int num : arr)
		cout << num << " ";
	cout << endl;
	
	pushZerosToEnd(arr);

	for (int num : arr)
		cout << num << " ";
	return 0;
}
