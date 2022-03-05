/*
//https://leetcode.com/problems/valid-anagram/
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example 1:

Input: s = "anagram", t = "nagaram"  

 O(n+m) m==n O(n+n) = O(n) , O(1)
   a: 0,
   n : 0,
   g: 0
   r: 0
   m: 0
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

*/

// Update the metrics



#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool checkAnagram(string s, string t){
  if(s.length()!=t.length()) return false;
  
  unordered_map<char,int> freq;
  
  // To enter the characters and increment the frequency in map
  for(int i=0;i<s.size();i++){
    freq[s[i]]++;
  }
  
  // to decrement the frequency in the map
  for(int i=0;i<t.size();i++){
    // find the character in map
    auto check = freq.find(t[i]);
    if(check == freq.end()){
      return false;
    }else{
      freq[t[i]]--;
    }
  }
  
  for(auto i: freq){
    if(i.second!=0){
      return false;
    }
  }
  
  return true;
  
}


int main()
{   
    string s = "anagram";
    string t = "naagrma";
  
    if(checkAnagram(s,t)){
      cout << "Anagram" << endl;
    }else{
      cout << "Not anagram" << endl;
    }
    return 0;
}
