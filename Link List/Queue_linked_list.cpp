// Queue – Linked List Implementation

// In this article, the Linked List implementation of the queue data structure is discussed and implemented. Print ‘-1’ if the queue is empty.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

class Node {
    public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

class Queue {
    Node* front, *rear;

    public:
        Queue() {front = rear = nullptr; }


        bool isEmpty() {
            if (front == nullptr) {
                return true;
            }
            return false;
        }
    
    //function to add an element to the queue
    void enqueue (int new_data) {
        Node* new_node = new Node(new_data);

        if (this->isEmpty()) {
            front = rear = new_node;
            return;
        }

        rear ->next = new_node;
        rear = new_node;
    }

    //remove the element 
    void dequeue() {

        if (this->isEmpty()) {
            cout << "Queue underflow\n";
            return;
        }

        Node* temp = front;
        front= front->next;

        if(front == nullptr)
            rear= nullptr;

        delete temp;
    }

    int getFront() {
        if (this->isEmpty()) {
            cout << "Queue is Empty\n";
            return INT_MIN;
        }
        return front->data;
    }

    int getRear() {
        if (this->isEmpty()) {
            cout << "Queue is Empty\n";
            return INT_MIN;
        }
        return rear->data;
    }

};


int32_t main(){

    Queue q;

    q.enqueue(10);
    q.enqueue(20);

    cout << "Queue Front: " <<q.getFront()<<endl;
    cout << "Queue Rear: " <<q.getRear()<<endl;

    q.dequeue();
    q.dequeue();


    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);


    q.dequeue();

    cout << "Queue Front: " <<q.getFront()<<endl;
    cout << "Queue Rear: " <<q.getRear()<<endl<<endl;

    return 0;
}