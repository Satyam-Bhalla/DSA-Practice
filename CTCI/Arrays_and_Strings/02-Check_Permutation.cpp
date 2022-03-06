/*
    Given 2 strings check if one is a permutation of another
*/
#include <bits/stdc++.h>

using namespace std;

// method 1
bool checkPermutation(string s, string t){
    if(s.length() != t.length())
        return false;
    unordered_map<char, int> freq;
    // To enter the characters and increment the frequency in map
    for(int i = 0; i < s.size(); i++){
        freq[s[i]]++;
    }

    // to decrement the frequency in the map
    for(int i = 0; i < t.size(); i++){
        // find the character in map
        auto check = freq.find(t[i]);
        if (check == freq.end()){
            return false;
        }
        else{
            freq[t[i]]--;
        }
    }

    for(auto i : freq){
        if (i.second != 0)
        {
            return false;
        }
    }
    return true;
}


// method 2
bool checkPermutationSorting(string s,string t){
    if(s.length() != t.length()) return false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    for(int i=0;i<s.length();i++){
        if(s[i]!=t[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s = "hello";
    string t = "eldlho";
    // if (checkPermutation(s, t))
    //     cout << "String is permuatation" << endl;
    if(checkPermutationSorting(s,t))
        cout << "String is permuatation" << endl;
    else
        cout << "String is not permutation" << endl;

    return 0;
}