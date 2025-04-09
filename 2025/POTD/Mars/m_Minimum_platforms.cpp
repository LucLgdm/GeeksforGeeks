#include <bits/stdc++.h>
using namespace std;

/*********************************************************************************************************
 * You are given the arrival times arr[] and departure times dep[] of all trains
 * that arrive at a railway station on the same day.
 * Your task is to determine the minimum number of platforms required at the station
 * to ensure that no train is kept waiting.
 * At any given time, the same platform cannot be used for both the arrival of one train
 * and the departure of another. Therefore, when two trains arrive at the same time,
 * or when one arrives before another departs, additional platforms are required
 * to accommodate both trains.
 * 
 * Examples:
 * 
 * Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
 * Output: 3
 * Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
 **********************************************************************************************************/

int findPlatform(vector<int>& arr, vector<int>& dep) {
	// Your code here
	int n = arr.size();
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());

	int platforms = 0, max_platforms = 0;
	int i = 0, j = 0;

	while(i < n && j < n){
		if (arr[i] <= dep[j]){
			platforms++;
			i++;
		}else{
			platforms--;
			j++;
		}
		max_platforms = max(max_platforms, platforms);
	}
	return max_platforms;
}

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum platforms required: " << findPlatform(arr, dep) << endl;
    return 0;
}