/*
    A string s is nice if, for every letter of the alphabet that s contains, it appears both in 
    uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' 
    and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

    Given a string s, return the longest substring of s that is nice. If there are multiple, 
    return the substring of the earliest occurrence. If there are none, return an empty string.

    Example 1:
    Input: s = "YazaAay"
    Output: "aAa"
    Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
    "aAa" is the longest nice substring.
    
    Example 2:
    Input: s = "Bb"
    Output: "Bb"
    Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
    
    Example 3:
    Input: s = "c"
    Output: ""
    Explanation: There are no nice substrings.
*/

#include <bits/stdc++.h>

using namespace std;


string longestNiceSubstring(string s) {
    if(s.size() < 2) {
        return "";
    }
    vector<int> a(26), A(26);
    for(char c: s) {
        if(isupper(c)) {
            A[c-'A']=1;
        } else {
            a[c-'a']=1;
        }  
    }
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        if(a[tolower(c)-'a'] && A[toupper(c)-'A']) {
            continue;
        }
        string pre = longestNiceSubstring(s.substr(0, i));
        string suf = longestNiceSubstring(s.substr(i+1));
        if(pre.size() >= suf.size()) {
            return pre;
        } else {
            return suf;
        }
    }
    return s;
}

int main() {
    string s = "YazaAay";
    cout << longestNiceSubstring(s) << endl;
    return 0;
}