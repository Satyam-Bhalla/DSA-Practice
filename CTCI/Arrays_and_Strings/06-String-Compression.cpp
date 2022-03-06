/*
    Implement a method to perform basic string compression using the counts of repeated characters.
    For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string.
    You can assume the string has only uppercase and lowercase letters (a-z).

*/

#include <bits/stdc++.h>

using namespace std;

string compress(string s){
    string compressed = "";
    int count = 1;
    for(int i=0;i<s.length();i++){
        if(i+1<s.length() && s[i]==s[i+1]){
            count++;
        }
        else{
            compressed += s[i];
            compressed += to_string(count);
            count = 1;
        }
    }
    if(compressed.length()>s.length()){
        return s;
    }
    return compressed;
}

int main(){
    string s = "abcdddddd";
    cout << compress(s) << endl;
    return 0;
}

