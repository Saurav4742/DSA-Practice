// Given a linked list, the task is to reverse the linked list by changing the links between nodes.

// Using Iterative Method – O(n) Time and O(1) Space:
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

class Node {
    public:

    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next  = nullptr;
    }
};
Node* reverseList(Node* head){
    // initilise the pointer
    Node *curr = head ,*prev = nullptr ,*next;

    // Traversal all the node of link list
    while(curr != nullptr) {
        
        // store next
        next = curr -> next;

        // reverse current node's next pointer
        curr -> next = prev;

        // move pointer one position ahead
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* node) {
    while(node != nullptr) {
        cout<<" " <<node -> data;
        node = node -> next;
    }
}

int32_t main(){

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = new Node(5);

    cout<< "given link list: ";
    printList(head);

    head = reverseList(head);

    cout<<"\nReversed Linked List:";
    printList(head);

    return 0;
}
*/

// [Alternate Approach – 1] Using Recursion – O(n) Time and O(n) Space: 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

class Node {
    public:

    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next  = nullptr;
    }
};
Node* reverseList(Node* head) {
    if(head == NULL || head-> next == NULL) {
        return head;
    }

    Node* rest = reverseList(head->next);

    head -> next -> next = head;
    head -> next = NULL;

    return rest;
}

void printList(Node* node) {
    while(node != nullptr) {
        cout<<" " <<node -> data;
        node = node -> next;
    }
}


int32_t main(){

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = new Node(5);

    cout<< "given link list: ";
    printList(head);

    head = reverseList(head);

    cout<<"\nReversed Linked List:";
    printList(head);

    return 0;
}