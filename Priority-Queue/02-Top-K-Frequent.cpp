/**/

#include <bits/stdc++.h>

using namespace std;
struct MyComp {
    bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
        if(a.first != b.first) {
            return a.first > b.first;
        }
        else {
            return a.second < b.second;
        }
    }
};
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> hashmap;
    for(string& word : words) {
        hashmap[word] += 1;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
    for(auto it = hashmap.begin(); it != hashmap.end(); ++it) {
        pq.push(make_pair(it->second, it->first));
        if(pq.size() > k) pq.pop();
    }
    vector<string> res;
    while(!pq.empty()) {
        res.insert(res.begin(), pq.top().second);
        pq.pop();
    }
    return res;
}

int main(){
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;
    vector<string> res = topKFrequent(words, k);
    for(auto word : res) {
        cout << word << endl;
    }
    return 0;
}