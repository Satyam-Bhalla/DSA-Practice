/*
    Given a binary tree, determine if it is height-balanced.
    For this problem, a height-balanced binary tree is defined as:
    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: true

    Example 2:
    Input: root = [1,2,2,3,3,null,null,4,4]
    Output: false
    
    Example 3:
    Input: root = []
    Output: true
*/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class node{
    public:
        int data;
        node *left = NULL;
        node *right = NULL;
        node(int d){
            data = d;
        }

};

int height(node* root) { 
    // An empty tree has height -1
    if (root == NULL) {
      return -1;
    }
    return 1 + max(height(root->left), height(root->right));
  }

bool isBalanced(node* root) {
    // An empty tree satisfies the definition of a balanced tree
    if (root == NULL) {
        return true;
    }

    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return abs(height(root->left) - height(root->right)) < 2 &&
        isBalanced(root->left) &&
        isBalanced(root->right);
}


int main(){
    node* root = new node(3);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);
    root->right->left->left = new node(8);
    cout << isBalanced(root) << endl;

    return 0;
}
