/*
    Implement an algorith to determine if a string has all unique characters.
     What if you cannot use additional data structures
*/

#include <bits/stdc++.h>

using namespace std;

// Assuming all charcters are smallcase english alphabets
bool isUnique(string s){
    if(s.length()>26) return false;
    int arr[26];
    memset(arr, 0, sizeof(arr));
    for(int i=0;i<s.length();i++){
        if(arr[s[i]-'a']!=0){
            return false;
        }
        arr[s[i]-'a']++;
    }
    return true;
}

// Space optimised
bool optimisedIsUnique(string s){
    int checker = 0;
    for(int i=0;i<s.length();i++){
        int val = s[i]-'a';
        if((checker & (1<<val))>0){
            return false;
        }
        checker |= (1<<val);
    }
    return true;
}

int main(){
    string str;
    cin >> str;
    if(optimisedIsUnique(str)){
        cout << "String is unique" << endl;
    }else{
        cout << "String is not unique" << endl;
    }
    
    return 0;
}