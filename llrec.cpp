#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    Node* temp = head;
    if (head == nullptr){
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    head = head->next;
    llpivot(head, smaller, larger, pivot);

    if (pivot >= temp->val){
        temp->next = smaller;
        smaller = temp;
    }
    else{
        temp->next = larger;
        larger = temp;   
    }


}