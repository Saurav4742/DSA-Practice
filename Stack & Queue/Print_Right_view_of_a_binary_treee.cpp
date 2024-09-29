// Print Right View of a Binary Tree

// Given a Binary Tree, the task is to print the Right view of it. The right view of a Binary Tree is a set of rightmost nodes for every level.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

class Node {
    public:
        int data;
        Node *left, *right;

        Node(int x) {
            data = x;
            left = right = nullptr;
        }
};

void RecursiveRightView(Node *root,int level, int& maxLevel, vector<int>&result) {
    if (!root) return;

    if (level > maxLevel) {
        result.push_back(root->data);
        maxLevel = level;
    }

    RecursiveRightView(root->right, level + 1, maxLevel, result);
    RecursiveRightView(root->left,level + 1, maxLevel, result);
}
// function to return the right the right view
vector<int> rightView(Node *root) {
    vector<int> result;
    int maxLevel = -1;

    RecursiveRightView(root,0,maxLevel,result); //start recursion with root at level 0

    return result; 
}

void printArray(vector<int>& arr) {
    for (int val : arr) {
        cout <<val<<" ";
    }
    cout <<endl;
}

int32_t main(){

    // Representation of the input tree:
    //         1
    //        / \
    //       2   3
    //           / \   
    //          4   5  
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);
    
    printArray(result);    
    return 0;
}