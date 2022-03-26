#include <bits/stdc++.h>

using namespace std;

vector<string> split(string &s, char d) {
    vector<string> ans;
    stringstream ss(s);
    string t;
    while (!ss.eof()) {
        getline(ss, t, d);
        ans.push_back(t);
    }
    return ans;
}

int main(){
    string s = "1,2,3,4,5,6,7,8";
    vector<string> v = split(s, ',');
    for (auto i : v) {
        cout << i << endl;
    }
    return 0;
}