#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

// BFS from given source s
void bfs(vector<vector<int>> &adj, int s, vector<bool>& visited) {
    //create a queue for BFS
    queue<int> q;

    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty()) {

        // Dequeue a vertex from queue and print it
        int curr = q.front();
        q.pop();
        cout << curr<<" ";

        // Get all adjacent vertices of the dequeued 
        // vertex curr If an adjacent has not been 
        // visited, mark it visited and enqueue it
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}


// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);  //undirected graph
}

int32_t main(){

    int V = 5; //no. of vertices
    vector<vector<int>> adj(V);    //Adjacency list representation of the Graph

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);

    // mark all the vertices as not visited
    vector<bool>visited(V, false);

    // perform BFS traversal starting from vertex 0
    cout<< "BFS starting from 0: ";
    bfs(adj, 0,visited);

    return 0;
}