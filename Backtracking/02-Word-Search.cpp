/*
    Given an m x n grid of characters board and a string word, return true if word exists in the 
    grid.
    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells 
    are horizontally or vertically neighboring. The same letter cell may not be used more than 
    once.
    Example 1:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true

    Example 2:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true

    Example 3:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    Output: false
*/

#include <bits/stdc++.h>

using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[0].size(); ++j)
        {
            if(adjacentSearch(board, word, i, j, 0))
                return true;
        }
    }
    return false;

}
bool adjacentSearch(vector<vector<char>>& board, const string& word, int i, int j, int index)
{
    if(index == word.size()) return true; // end condition
    if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) return false; // boundary of matrix
    if(board[i][j] != word[index]) return false; // do not match
    // match!
    board[i][j] = '*'; // change the content, to avoid duplicated search
    bool furtherSearch =  adjacentSearch(board, word, i+1, j, index+1) || // up
                            adjacentSearch(board, word, i-1, j, index+1) || // down
                            adjacentSearch(board, word, i, j-1, index+1) || // left
                            adjacentSearch(board, word, i, j+1, index+1);   // right
    
    board[i][j] = word[index]; // modify it back!
    return furtherSearch;
}

int main(){
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    return 0;
}