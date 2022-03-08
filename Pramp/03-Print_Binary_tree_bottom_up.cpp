#include<bits/stdc++.h>
#include <stack>
using namespace std;

class node{
    public:
        int data;
        node* left = NULL;
        node* right = NULL;
        node(int d){
            data = d;
        }
};

void Preorder(node *root){
    if(root==NULL){
        cout << " null ";
        return ;
    }

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

int height(node *root){
    if(root==NULL){
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1+max(h1,h2);
}

void traverseBottomToTop(node *root,int i,vector<vector<int>> &result){
    if(root==NULL){
        return;
    }
    result[i].push_back(root->data);

    traverseBottomToTop(root->left,i+1,result);
    traverseBottomToTop(root->right,i+1,result);

}

stack<int> bottomTopTraversal(node *root){
    queue<node*> q;
    stack<int> stk;
    q.push(root);
    stk.push(root->data);
    
    q.push(NULL);
    stk.push(-1);
    

    while(!q.empty()){
        node *f = q.front();
        if(f==NULL){
            stk.push(-1);
            // cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            stk.push(f->data);
            // cout << f->data << " ";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return stk;    
}

/*
                3
            9        20
                  15    7
*/


int main(){
    // node* root = new node(3);
     node *root = new node(3);
    root->left = new node(9);
    root->right = new node(20);
  
    root->right->left = new node(15);
    root->right->right = new node(7);
    // Preorder(root);
    cout << endl;
    int h = height(root);
    vector<vector<int>> result{10};
    traverseBottomToTop(root,0,result);
    for(int i=9;i>=0;i--){
        for(int j = 0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        if(result[i].size()!=0){
            cout << endl;
        }
    }
    // stack<int> result = bottomTopTraversal(root);
    // while(!result.empty()){
    //     if(result.top()==-1){
    //         cout << endl;
    //     }else{
    //         cout << result.top() << " ";
    //     }
    //     result.pop();
    // }
    return 0;
}