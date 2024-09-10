// Print Adjacency List for a Directed Graph

// Problem: Given the adjacency list and number of vertices and edges of a graph, the task is to represent the adjacency list for a directed graph.

// Approach (using STL):

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int
    // for add Edges
void addEdges(vector<int> adj[],int u , int v){
    adj[u].push_back(v);
}

// to initilise the  adjacency list of the given graph
void adjacencyList(vector<int>adj[],int v) {
    for (int i = 0; i< v; i++) {
        cout << i <<"->";
        for (int& x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

void initGraph(int v,int edges[3][2], int noOfEdges) {
    vector<int> adj[v];  

    // traverse edges as adjacency list
    for (int i = 0; i<noOfEdges; i++) {
        addEdges(adj, edges[i][0],edges[i][1]);
    }

    // function call to print adjacency list 
    adjacencyList(adj,v);
}
int32_t main(){

int v = 3;    //vertices

int edges[3][2] = {{0,1},{1,2},{2,0}};
int noOfEdges = 3;

initGraph(v,edges,noOfEdges); //function call
    return 0;
}

// Input: V = 4, edges[][] = {{0, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 0}}
// Output: 0 -> 1
//         1 -> 2 3
//         2 -> 3
//         3 -> 0/

