#include <iostream>
using namespace std;


/****************************************************************************************************************
* Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
* If the characters in str1 can be changed to get str2, then two strings, str1 and str2, are isomorphic.
* A character must be completely swapped out for another character while maintaining the order of the characters.
* A character may map to itself, but no two characters may map to the same character.
* Expected Time Complexity: O(|str1|+|str2|).
* Expected Auxiliary Space: O(Number of different characters).
* Note: |s| represents the length of string s.
* Example :
* Input:
* str1 = aab, str2 = xxy
* Output: 1
* Explanation: 
* There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
*****************************************************************************************************************/

bool areIsomorphic(string str1, string str2)
{
  // the strings must have the same length
  if(str1.length() != str2.length()){
      return false;
  }
  
  int n = str1.length();
  unordered_map<char, char> charMap;
  unordered_map<char, bool> usedMap;
  
  for(int i = 0; i < n; i++){
      char char1 = str1[i];
      char char2 = str2[i];
      
      // On regarde si une correspondance existe deja
      if(charMap.find(char1) != charMap.end()){
          // On regarde si la correspondance est correcte
          if(charMap[char1] != char2){
              return false;
          }
      }else{
          if(usedMap.find(char2) != usedMap.end()){
              return false;
          }
      }
      
      // On fait la correspondance
      charMap[char1] = char2;
      usedMap[char2] = true;
      
  }
  return true;
  
}
