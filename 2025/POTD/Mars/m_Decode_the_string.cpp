#include <bits/stdc++.h>
using namespace std;

/***************************************************************************************************
 * Given an encoded string s, the task is to decode it. The encoding rule is :
 * 
 * k[encodedString], where the encodedString inside the square brackets is being
 * repeated exactly k times. Note that k is guaranteed to be a positive integer,
 * and encodedString contains only lowercase english alphabets.
 * 
 * Note: The test cases are generated so that the length of the output string will never exceed 105 .
 * Input: s = "3[b2[ca]]"
 * Output: "bcacabcacabcaca"
 ****************************************************************************************************/

string decodedString(string &s) {
	// code here
	stack<int> counts;
	stack<string> strings;
	string curr_string = "";
	int	curr_number = 0;

	for(char c : s){
		if (isdigit(c))
			curr_number = curr_number * 10 + (c - '0');
		else if(c == '['){
			counts.push(curr_number);
			strings.push(curr_string);
			curr_string = "";
			curr_number = 0;
		}else if (c == ']'){
			string tmp = curr_string;
			int repeat_count = counts.top();
			counts.pop();
			for(int i = 0; i < repeat_count - 1; i++){
				curr_string += tmp;
			}
			curr_string = strings.top() + curr_string;
			strings.pop();
		}else
			curr_string += c;
	}
	return curr_string;
}