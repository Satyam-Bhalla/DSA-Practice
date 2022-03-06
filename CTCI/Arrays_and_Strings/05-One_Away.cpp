/*
    One Away: There are three types of edits that can be performed on strings: insert a character, 
    remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
*/
#include <bits/stdc++.h>

using namespace std;

bool OneAway(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    if (abs(len1 - len2) > 1) {
        return false;
    }
    int i = 0, j = 0;
    int count = 0;
    while (i < len1 && j < len2) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            if (count == 0) {
                count++;
                if (len1 > len2) {
                    i++;
                } else {
                    j++;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

int main(){
    string s1 = "pale";
    string s2 = "ples";
    cout << OneAway(s1, s2) << endl;

    return 0;
}