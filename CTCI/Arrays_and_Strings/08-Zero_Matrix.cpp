/*
    Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
*/


#include<bits/stdc++.h>
#include "../utils/vector.h"
using namespace std;

void update_matrix(vector<vector<int>> &temp,int row,int column){
    for(int j=0;j<temp[row].size();j++){
        temp[row][j]=0;
    }
    for(int i=0;i<temp.size();i++){
        temp[i][column]=0;
    }
}

vector<vector<int>> makeZeroes(vector<vector<int>> &arr){
    vector<vector<int>> temp = arr;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j]==0){
                update_matrix(temp,i,j);
            }
        }
    }
    return temp;
    
}


int main(){
    vector<vector<int>> arr = {{1,2,3},{4,0,6},{7,8,9}};
    vector<vector<int>> temp = makeZeroes(arr);
    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i].size();j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}