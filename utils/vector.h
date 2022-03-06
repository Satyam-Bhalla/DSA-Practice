#include<iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;v[i].size();j++){
            cout << v[i][j] << " ";
        }
    }
}