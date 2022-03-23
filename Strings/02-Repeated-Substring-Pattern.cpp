/*
    Given a string s, check if it can be constructed by taking a substring of it and appending 
    multiple copies of the substring together.
    
    Example 1:
    Input: s = "abab"
    Output: true
    Explanation: It is the substring "ab" twice.
    
    Example 2:
    Input: s = "aba"
    Output: false

*/
#include <bits/stdc++.h>
using namespace std;

/*
    s = "abab"
    s+s = "abababab"

    On removing the first and the last characters, we get:
    (s+s).substr(1, 2*s.size()-2) = "bababa"

    This new string, "bababa" still contains the original string, "abab".
    Thus there exists some repeated pattern in the original string itself.
*/
bool repeatedSubstringPattern(string s) {
    return (s + s).substr(1, 2*s.size()-2).find(s) != -1;
}


int main(){
    string s = "abab";
    cout << repeatedSubstringPattern(s) << endl;
    return 0;
}