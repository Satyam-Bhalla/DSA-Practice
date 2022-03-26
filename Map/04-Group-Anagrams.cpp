/*
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
    typically using all the original letters exactly once.
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string t = s; 
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    vector<vector<string>> anagrams;
    for (auto p : mp) { 
        anagrams.push_back(p.second);
    }
    return anagrams;
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (auto v : ans) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}