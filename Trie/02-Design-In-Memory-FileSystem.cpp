#include <bits/stdc++.h>

using namespace std;

class FileSystem {
private:
    struct TrieNode {
        bool isFile;
        string content;
        unordered_map<string, TrieNode *> children;
        TrieNode() : isFile(false) {}
    };

    TrieNode *root;
    
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> getStrs(string &path) {
        vector<string> ans;
        int i = 1, j = 1;
        while (j <= path.length()) {
            if (i != j && (j == path.length() || path[j] == '/')) {
                ans.push_back(path.substr(i, j - i));
                i = j + 1;
            }
            ++j;
        }
        return ans;
    }
    
    vector<string> ls(string path) {
        vector<string> strs = getStrs(path);
        TrieNode *curr = root;
        for (string &str : strs)
            curr = curr->children[str];
        
        if (curr->isFile)
            return {strs.back()};
        
        vector<string> ans;
        for (auto &p : curr->children)
            ans.push_back(p.first);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        vector<string> strs = getStrs(path);
        TrieNode *curr = root;
        for (string &str : strs) {
            if (!curr->children.count(str))
                curr->children[str] = new TrieNode();
            curr = curr->children[str];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> strs = getStrs(filePath);
        TrieNode *curr = root;
        for (string &str : strs) {
            if (!curr->children.count(str))
                curr->children[str] = new TrieNode();
            curr = curr->children[str];
        }
        curr->isFile = true;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> strs = getStrs(filePath);
        TrieNode *curr = root;
        for (string &str : strs)
            curr = curr->children[str];
        return curr->content;
    }
};

int main(){
    FileSystem* obj = new FileSystem();
    obj->mkdir("/a");
    obj->mkdir("/a/b");
    obj->mkdir("/a/b/c");
    obj->addContentToFile("/a/b/c/d", "hello");
    vector<string> param_2 = obj->ls("/a");
    for (auto i : param_2)
        cout << i << endl;
    cout << obj->readContentFromFile("/a/b/c/d") << endl;
    return 0;
}