/*
    https://leetcode.com/problems/string-without-aaa-or-bbb/
    Given two integers a and b, return any string s such that:
    s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
    The substring 'aaa' does not occur in s, and
    The substring 'bbb' does not occur in s.

    Example 1:
    Input: a = 1, b = 2
    Output: "abb"
    Explanation: "abb", "bab" and "bba" are all correct answers.
    
    Example 2:
    Input: a = 4, b = 1
    Output: "aabaa"
*/

#include<bits/stdc++.h>

using namespace std;
 string strWithout3a3b(int a, int b) {
    if(a == 0) return string(b, 'b');
    else if(b == 0) return string(a, 'a');
    else if(a == b) return "ab" + strWithout3a3b(a - 1, b - 1);
    else if(a > b) return "aab" + strWithout3a3b(a - 2, b - 1);
    else return strWithout3a3b(a - 1, b - 2) + "abb";

}


int main(){
    int a = 1, b = 2;
    string s = strWithout3a3b(a,b);
    cout << s << endl;
    return 0;
}