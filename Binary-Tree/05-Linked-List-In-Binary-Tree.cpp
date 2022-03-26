/*
    Given a binary tree root and a linked list with head as the first node. 
    Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
    In this context downward path means a path that starts at some node and goes downwards.

    Example 1:
    Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: true
    Explanation: Nodes in blue form a subpath in the binary Tree.  

    Example 2:
    Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: true

    Example 3:
    Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: false
    Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>

using namespace std;

bool findSubPath(ListNode* head, TreeNode* root) {
    if (!head) return true;
    if (!root) return false;
    return head->val == root->val && (findSubPath(head->next, root->left) || findSubPath(head->next, root->right));
}

bool isSubPath(ListNode* head, TreeNode* root) {
    if (!root) return false;
    return findSubPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(1);
    root->left->right->right->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(3);

    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(8);

    cout << isSubPath(head, root) << endl;
    return 0;
}