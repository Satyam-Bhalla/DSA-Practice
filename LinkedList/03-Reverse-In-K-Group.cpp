/*
    Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]
    
    Example 2:
    Input: head = [1,2,3,4,5], k = 3
    Output: [3,2,1,4,5]
*/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* reverse(ListNode* first, ListNode* last){
    ListNode* prev = last;

    while ( first != last )
    {
        auto tmp = first->next;
        first->next = prev;
        prev = first;
        first = tmp;
    }

    return prev;
}
    
ListNode* reverseKGroup(ListNode* head, int k) 
{
    auto node=head;
    for (int i=0; i < k; ++i)
    {
        if ( ! node  )
            return head; // nothing to do list too sort
        node = node->next;
    }

    auto new_head = reverse( head, node);
    head->next = reverseKGroup( node, k);
    return new_head;
}


int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next->next->next->next->next->next = new ListNode(11);
    head->next->next->next->next->next->next->next->next->next->next->next = new ListNode(12);
    head->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(13);
    ListNode* res = reverseKGroup(head, 3);
    while ( res )
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}