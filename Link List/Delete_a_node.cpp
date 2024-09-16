// Delete a Node from linked list without head pointer

// You are given a singly linked list and pointer which is pointing to the node which is required to be deleted. Any information about the head pointer or any other node is not given. You need to write a function to delete that node from the linked list. Your function will take only one argument, i.e., a pointer to the node which is to be delete.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

struct Node {
    int data;
    struct Node* next;
};

void deleteNodeWithoutHead(struct Node* pos) {
    if (pos == NULL)  //if link list is empty
        return;
    else {
        if (pos->next == NULL) {
            cout<<"tis is last node, require head, can't" "be freed\n";
            return;
        }
        struct Node* temp = pos->next;

        pos->data = pos->next->data; //copy data of the next node to current node

        pos->next = pos->next->next;  //perform conventional deletion

        free(temp);
    }
}

void print(Node* head) {

    Node* temp = head;
    while (temp) {
        cout <<temp->data<<"->";
        temp = temp->next;
    }
    cout <<"NULL";
}
void push(struct Node** head_ref,int new_data) {
    struct Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}


int main() {
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
    cout<< "Initial Linked LIst: \n";
    print(head);
    cout<<endl<<endl;

    Node* del = head->next; //delete 15 without sending head

    deleteNodeWithoutHead(del);

    cout<<"Final linked list after deletion of 15:\n";
    print(head);

    return 0;
}