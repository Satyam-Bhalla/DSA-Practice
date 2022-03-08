#include <iostream>

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

void printList(node *root){
    while(root->next!=NULL){
        cout << root->val << "->";
        root = root->next;
    }
    cout << endl;
}


int main(){
    node* l1 = new node(1);
    l1->next = new node(2);
    l1->next->next = new node(3);

    node* l2 = new node(1);
    l2->next = new node(3);
    l2->next->next = new node(4);

    node* l3 = mergeTwoLists(l1,l2);
    printList(l3);
    return 0;
}

