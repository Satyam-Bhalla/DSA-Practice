/*
    You are given two strings word1 and word2. Merge the strings by adding letters in alternating 
    order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
    Return the merged string.
    Example 1:

    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"
    Explanation: The merged string will be merged as so:
    word1:  a   b   c
    word2:    p   q   r
    merged: a p b q c r
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    string w1 = "abc";
    string w2 = "pqr";
    string res;
    for (auto i = 0; i < max(w1.size(), w2.size()); ++i) {
        if (i < w1.size())
            res += w1[i];
        if (i < w2.size())
            res += w2[i];
    }
    cout << res << endl;
    return 0;
}