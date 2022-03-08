/*
    String Rotations: Assume you have a method isSubstring which checks if one word is a substring of another. 
    Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
*/

#include <iostream>

using namespace std;


bool isSubstring(string s1, string s2){
    if(s1.length() < s2.length()) return 0;
    for(int i=0;i<s1.length()-s2.length()+1;i++){
        if(s1.substr(i,s2.length()) == s2) return true;
    }
    return false;
}

bool isRotation(string s1, string s2){
    if(s1.length() != s2.length()) return false;
    string s1s1 = s1 + s1;
    return isSubstring(s1s1,s2);
}

int main(){
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    if(isRotation(s1, s2)) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}