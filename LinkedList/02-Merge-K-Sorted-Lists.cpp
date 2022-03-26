/*
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.

    Example 1:
    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
    1->4->5,
    1->3->4,
    2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6

    Example 2:
    Input: lists = []
    Output: []

    Example 3:
    Input: lists = [[]]
    Output: []
*/

#include <bits/stdc++.h>

using namespace std;

class node{
    public:
        int val;
        node* next=NULL;
        node(int d){
            val=d;
        }
};


node* mergeTwoLists(node* l1, node* l2) {
        
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
}


node *mergeKLists(vector<node *> &lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }

void printList(node *root){
    while(root!=NULL){
        cout << root->val;
        if(root->next==NULL){
            cout << endl;
        }else{
            cout << "->";
        }
        root = root->next;
    }
}


int main(){
    node* l1 = new node(1);
    l1->next = new node(2);
    l1->next->next = new node(3);

    node* l2 = new node(1);
    l2->next = new node(3);
    l2->next->next = new node(4);

    node* l3 = new node(1);
    l3->next = new node(2);
    l3->next->next = new node(4);
    l3->next->next->next = new node(5);
    l3->next->next->next->next = new node(6);

    vector<node *> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    node* l4 = mergeKLists(lists);
    printList(l4);
    return 0;
}

