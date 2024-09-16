// Pairwise Swap Nodes of a given Linked List

// Given a singly linked list, write a function to swap elements pairwise. 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int
class Node {
    public:
    int data;
    Node* next;
};
void pairwiseswap(Node* head) {
    Node* temp = head;

    while (temp != NULL && temp->next !=NULL) {
        swap(temp->data, temp->next->data);
        temp = temp->next->next;
    }
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();

    new_node->data = new_data;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data <<" ";
        node = node->next;
    }
}

int32_t main(){

    Node* start = NULL;

    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout <<"linked list before calling pairwiseswap()\n";

    printList(start);

    pairwiseswap(start);

    cout << "\nLinked list"<<"after calling pairwiseswap()\n";

    printList(start);

    return 0;
}
// Input : 1->2->3->4->5->6->NULL 
// Output : 2->1->4->3->6->5->NULL