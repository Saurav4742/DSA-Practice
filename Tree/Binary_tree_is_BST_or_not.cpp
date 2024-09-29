// Check if a Binary Tree is BST or not

// Given the root of a binary tree. Check whether it is a Binary Search Tree or not. A Binary Search Tree (BST) is a node-based binary tree data structure with the following properties. 

//* All keys in the left subtree are smaller than the root and all keys in the right subtree are greater.
//* Both the left and right subtrees must also be binary search trees.
//* Each key must be distinct.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

bool isBSTutil(Node* node, int min, int max) {
    if (node == nullptr) return true;

    if (node->data < min || node->data > max) return false;

    return isBSTutil(node->left,min,node->data - 1) && isBSTutil(node->right, node->data+1,max);
}

bool isBST(Node* root) {
    return isBSTutil(root, INT_MIN, INT_MAX);
}

int32_t main(){

        // Create a sample binary tree
    //      4
    //    /   \
    //   2     5
    //  / \
    // 1   3

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    if (isBST(root)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
        return 0;
}
