/*
    Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/


#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int l=0, r = n-1;
    
    unordered_set<char> visited;
    
    int maxStr = 0;

    for(int r=0;r<n;r++)
    {
        if(visited.find(s[r])==visited.end())
        {
            visited.insert(s[r]);
            maxStr = max(maxStr,r-l+1);
            
        }
        else
        {
            while(l!=r && s[l]!=s[r])
                visited.erase(s[l++]);
            
            //Removing and adding the same element
            visited.erase(s[l++]);
            visited.insert(s[r]);
            
            maxStr = max(maxStr,r-l+1);
        }
    }
    
    return maxStr;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}