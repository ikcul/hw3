#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    Node* temp = head;
    if (head == nullptr){
        return;
    }else if (pivot >= head->val){
        head = temp->next;
        temp->next = smaller;
        smaller = temp;
        appendToEnd(smaller, temp);
        llpivot(head, smaller, larger, pivot);
    }else{
        head = temp->next;
        temp->next = larger;
        larger = temp;
        appendToEnd(larger, temp);
        llpivot(head, smaller, larger, pivot);
    }
}

void appendToEnd(Node*& head, Node* node){
    if (head->next == nullptr){
        head->next = node;
        node->next = nullptr;
    }else {
        appendToEnd(head->next, node);
    }
}