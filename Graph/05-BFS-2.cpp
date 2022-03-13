#include<bits/stdc++.h>

using namespace std;

// Input
// 5 6
// 0 1
// 1 2
// 1 3
// 3 4
// 4 2
// 3 2
// Output 0 1 2 3 4





vector<vector<int>> g;
vector<bool> v; // visited





// For directed graph
void add_edge(int a,int b){
    g[a].push_back(b);

    // For undirected graph
    // g[b].push_back(a);
}


void bfs(int u){
    queue<int> q;
    // Push in the queue for processing
    q.push(u);

    // Update the visited vector for u node
    v[u] = true;

    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout << f << " ";

        // Push all the neighbours of u node in the queue
        for(auto i=g[f].begin(); i!=g[f].end(); i++){
            if(!v[*i]){
                q.push(*i);
                v[*i] = true;
            }
        }
    }

}




int main(){
    int n,e;
    cin >> n >> e;
    v.assign(n,false);
    g.assign(n,vector<int>());

    int a,b;
    for(int i=0;i<e;i++){
        cin >> a >> b;
        add_edge(a,b);
    }


    // BFS
    for(int i=0;i<n;i++){
        if(!v[i]){
            bfs(i);
        }
    }

}