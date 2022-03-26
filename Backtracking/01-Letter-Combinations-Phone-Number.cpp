/*
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

    A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Example 2:
    Input: digits = ""
    Output: []

    Example 3:
    Input: digits = "2"
    Output: ["a","b","c"]
*/
#include<bits/stdc++.h>
#include <cstring>
using namespace std;

const vector<string> pad = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

vector<string> letterCombinationsIterative(string digits) {
    if (digits.empty()) return {};
    vector<string> result;
    result.push_back("");

    for(auto digit: digits) {
        vector<string> tmp;
        for(auto candidate: pad[digit - '0']) {
            for(auto s: result) {
                tmp.push_back(s + candidate);
            }
        }
        result.swap(tmp);
    }
    return result;
}

vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
void helper(string &digits, int i, string &combi){
    if(i == digits.size()){
        ans.push_back(combi);    
        return;
    }
    for(auto c : mappings[digits[i] - '2']){
        combi.push_back(c);            // add a character from mappings for current position,
        helper(digits, i + 1, combi);  // and recurse for next positions
        combi.pop_back();              // backtrack
    }   
}

vector<string> letterCombinations(string digits) {
    if(digits == "") return ans;        
    string combination = "";
    helper(digits, 0, combination);
    return ans; 
}

// passing by reference ⬇️ so copies are not made at each function call
int main(){
    string digits = "23";
    vector<string> result = letterCombinations(digits);
    vector<string> result2 = letterCombinationsIterative(digits);
    for(auto s : result){
        cout << s << endl;
    }
    return 0;
}
