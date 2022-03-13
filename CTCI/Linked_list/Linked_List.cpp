/*
    Remove Duplicates: Write code to remove duplicates from an unsorted linked list.
*/
#include <iostream>

using namespace std;



class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
        }
};
int length(Node* head);

void insertAtHead(Node *&head,int val){
    if(head==NULL){
        head = new Node(val);
        return;
    }
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;

}


void insertAtTail(Node* &head,int val){
    if(head==NULL){
        Node* node = new Node(val);
        head = node;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* node = new Node(val);
    temp->next = node;
}


void insertAtMiddle(Node* &head,int val,int location){
    int len= length(head);
    if(location==1 or len==0){
        insertAtHead(head,val);
        return;
    }else if(location>=len){
        insertAtTail(head,val);
        return;
    }else{
        Node* prev = head;

        for(int i=1;i<location;i++){
            prev = prev->next;
        }
        Node* temp = new Node(val);

        temp->next = prev->next;
        prev->next = temp;
    }
}



void deleteHead(Node* &head){
    if(head==NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp; 
}

void deleteTail(Node* &head){
    if(head==NULL){
        return;
    }
    Node* node = head;
    while(node->next->next !=NULL){
        node = node->next;
    }
    Node* temp = node->next;
    node->next = NULL; 
    delete temp;
}

void deleteAtMiddle(Node* &head,int location){
     int len= length(head);
    if(location==1 or len==0){
        deleteHead(head);
        return;
    }else if(location>=len){
        deleteTail(head);
        return;
    }else{

    }
}


int length(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

int lengthRecusrive(Node *head,int count){
    if(head==NULL){
        return count;
    }
    return lengthRecusrive(head->next,count+1);
}

void printList(Node *head){
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* head = NULL;
    insertAtHead(head,5); 
    insertAtHead(head,4);   
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtMiddle(head,3,2);
    insertAtTail(head,6);
    deleteHead(head);
    deleteTail(head);
    printList(head);
    cout << length(head) << " " << lengthRecusrive(head,0) << endl;
    return 0;
}