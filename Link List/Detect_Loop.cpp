// Detect loop or cycle in a linked list

// Given a linked list, check if the linked list has a loop (cycle) or not. The below diagram shows a linked list with a loop.

// Detect loop in a linked list using Floyd’s Cycle-Finding Algorithm:

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this ->data = new_data;
        this ->next = nullptr;
    }
};
bool detectLoop(Node* head){
    Node *slow_p = head, *fast_p = head;



    // Loop that runs while fast and slow pointer are not
    // nullptr and not equal
    while (slow_p && fast_p && fast_p ->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if(slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

int32_t main(){

 // Create a hard-coded linked list:
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60
    Node* head = new Node(10);
    head-> next = new Node(20);
    head-> next-> next = new Node(30);
    head-> next-> next-> next = new Node(40);
    head-> next-> next-> next-> next = new Node(50);
    head-> next-> next-> next-> next-> next = new Node(60);

    // Creating a loop resulting in the linked list:
    // 10 -> 20 -> 30 -> 40 -> 10 -> 20 -> 30 ...
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop Found";
    else
        cout << "No Loop";
    return 0;    
}