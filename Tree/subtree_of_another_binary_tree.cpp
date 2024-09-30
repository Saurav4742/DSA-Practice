// Check if a Binary Tree is subtree of another binary tree 

// Given two binary trees, check if the first tree is a subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int value) {
        data = value;
        left = right = nullptr;
    }
};

bool areIdentical(Node* root1, Node* root2) {
    //base case
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return  (root1->data == root2->data && areIdentical(root1->left,root2->left) && areIdentical(root1->right, root2->right));
}

bool isSubtree(Node* T, Node* S){

    //base case
    if (S == NULL)
        return true;

    if (T == NULL)
        return false;

    if (areIdentical(T,S))   //check the tree with root as a current node
        return true;

    // if the tree with root as current node doesn't match then try left and right subtrees one by one
    return isSubtree(T->left,S) || isSubtree(T->right, S);
}

int32_t main(){

    // TREE 1
    /* Construct the following tree
            26
           /  \
          10   3
         / \    \
        4   6    3
         \
          30
    */
    Node* T = new Node(26);
    T->right = new Node(3);
    T->right->right = new Node(3);
    T->left = new Node(10);
    T->left->left = new Node(4);
    T->left->left->right = new Node(30);
    T->left->right = new Node(6);

    // TREE 2
    /* Construct the following tree
         10
        /  \
       4    6
        \
         30
    */
    Node* S = new Node(10);
    S->right = new Node(6);
    S->left = new Node(4);
    S->left->right = new Node(30);

    if (isSubtree(T, S))
        cout << "Tree 2 is subtree of Tree 1";
    else
        cout << "Tree 2 is not a subtree of Tree 1";

    return 0;
}