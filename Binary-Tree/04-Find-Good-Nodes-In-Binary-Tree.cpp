/*
    Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

    Return the number of good nodes in the binary tree.
    Input: root = [3,1,4,3,null,1,5]
    Output: 4
    Explanation: Nodes in blue are good.
    Root Node (3) is always a good node.
    Node 4 -> (3,4) is the maximum value in the path starting from the root.
    Node 5 -> (3,4,5) is the maximum value in the path
    Node 3 -> (3,1,3) is the maximum value in the path.

    Example 2:
    Input: root = [3,3,null,4,2]
    Output: 3
    Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
    Example 3:

    Input: root = [1]
    Output: 1
    Explanation: Root is considered as good.
*/

#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 int ans=0;
void pre(TreeNode* root,int max){
    if(!root)return;
    if(root->val >= max){ ans++; max=root->val; }
    pre(root->left,max);
    pre(root->right,max);
}

int goodNodes(TreeNode* root) {
    pre(root,INT_MIN);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(1);
    root->right->left->right = new TreeNode(5);
    root->right->right->left = new TreeNode(2);
    cout << goodNodes(root) << endl;
    
    return 0;
}