// Using Recursion:



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
int maxDepth(Node *node) {
    // base case
    if (node == nullptr)
    return 0;


    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);

    return max(lDepth,rDepth) + 1;
}

// Function to insert nodes in level order

Node* insertLevelorder(const vector<int>&values, Node* root , int i , int n) {
    if (i < n) {
        Node* temp = new Node(values[i]);
        root = temp;

        // insert left child
        root->left = insertLevelorder(values, root->left,2*i+1,n);

        // insert right child
        root->right = insertLevelorder(values,root->right,2*i+2,n);
    }
    return root;
}

int32_t main(){
    int n;
    cout<< "enter the number of nodes in the binary tree: ";
    cin>>n;

    vector<int>values(n);
    cout << "enter "<<n<<" values for the binary tree nodes:"<<endl;

    for(int i=0;i<n ;i++) {
        cin >>values[i];
    }

    Node* root = nullptr;
    root = insertLevelorder(values,root,0,n);

    cout <<"maximum Depth of the Bnary Tree: "<< maxDepth(root);
    return 0;
}



/*
// 2nd approach
// Using Level Order Traversal:

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the height (depth)
// of the tree
int height(Node* root) {
    if (!root) return 0;

    // Initializing a variable to count 
    // the height of the tree
    int depth = 0;

    queue<Node*> q;

    // Pushing the first level element 
    // along with nullptr
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // When nullptr is encountered, 
        // increment the depth
        if (temp == nullptr) {
            depth++;
          
            // If queue still has elements left, 
            // push nullptr again to the queue
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
          
            // If nullptr is not encountered, 
            // keep moving
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return depth;
}

// Function to insert nodes in level order

Node* insertLevelorder(const vector<int>&values, Node* root , int i , int n) {
    if (i < n) {
        Node* temp = new Node(values[i]);
        root = temp;

        // insert left child
        root->left = insertLevelorder(values, root->left,2*i+1,n);

        // insert right child
        root->right = insertLevelorder(values,root->right,2*i+2,n);
    }
    return root;
}
int main() {
        int n;
    cout<< "enter the number of nodes in the binary tree: ";
    cin>>n;

    vector<int>values(n);
    cout << "enter "<<n<<" values for the binary tree nodes:"<<endl;

    for(int i=0;i<n ;i++) {
        cin >>values[i];
    }

    Node* root = nullptr;
    root = insertLevelorder(values,root,0,n);

    cout <<"maximum Depth of the Bnary Tree: "<< height(root);
}

*/
