#include<bits/stdc++.h>

using namespace std;

void removeNeighbourIslands(vector<vector<char>>& grid,int i,int j){
    int m = grid.size();
    int n = grid[0].size();
    // Edge cases
    if(i<0 || i==m || j<0 || j==n || grid[i][j]=='0'){
        return;
    }
    grid[i][j] = '0';
    removeNeighbourIslands(grid,i-1,j);
    removeNeighbourIslands(grid,i+1,j);
    removeNeighbourIslands(grid,i,j-1);
    removeNeighbourIslands(grid,i,j+1);
    // For Diagonals
    // removeNeighbourIslands(grid,i+1,j+1);
    // removeNeighbourIslands(grid,i+1,j-1);
    // removeNeighbourIslands(grid,i-1,j+1);
    // removeNeighbourIslands(grid,i-1,j-1);
}



int numberOfIslands(vector<vector<char>>& grid){
    int m = grid.size();
    int n = m ? grid[0].size(): 0;
    int islands = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                islands++;
                removeNeighbourIslands(grid,i,j);
            }
        }
    }
    return islands;

}



int main(){
    vector<vector<char>> grid = {
                                 {'1','1','0','1','0'},
                                 {'1','1','0','1','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','0','0','0'}
                                };

    cout << numberOfIslands(grid) << endl;
}


/*
    1 0 0 0 0
    0 1 0 1 0
    0 0 0 0 0
    0 0 0 0 0

*/
