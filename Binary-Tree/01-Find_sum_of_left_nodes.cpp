/*
    Given the root of a binary tree, return the sum of all left leaves.
    Example 1:
        3
       / \
      9  20
        /  \
       15   7
    Input: root = [3,9,20,null,null,15,7]
    Output: 24
    Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
    Example 2:
    Input: root = [1]
    Output: 0

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


// Calculate sum of left child
int calculateSum(TreeNode* root,bool isleft){
    if (!root) return 0;
    if (!root->left && !root->right) return isleft ? root->val : 0;
    return calculateSum(root->left, true) + calculateSum(root->right, false);
}
int sumOfLeftLeaves(TreeNode* root) {
        return calculateSum(root,false);
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sumOfLeftLeaves(root) << endl;
    return 0;
}
