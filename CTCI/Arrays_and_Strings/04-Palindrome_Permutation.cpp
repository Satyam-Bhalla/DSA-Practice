/*
    Given a string write a function to check if it is a permutation of a palindrome.
    A palindrome is a word or phrase that is the same forwards and backwards.
    Example
    Input: Tact Coa
    Output: True (permutations: "taco cat", "atco cta", etc.)
    Input: aaaccb
    Output: False
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isPalindromePermutation(string s){
    unordered_map<char,int> m;

    // To eliminate spaces in the string
    int charCount = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] != ' '){
            charCount++;
            m[s[i]]++;
        }
        
    }
    if(charCount%2==0){
        for(auto charFreq:m){
            if(charFreq.second%2!=0){
                return false;
            }
        }
    }else{
        int oddCount = 0;
        for(auto charFreq:m){
            if(charFreq.second%2!=0){
                oddCount++;
            }
        }
        if(oddCount>1){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "Tact Coa";
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(isPalindromePermutation(s)) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}