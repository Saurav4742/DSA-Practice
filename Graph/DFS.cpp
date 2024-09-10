#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

void addEdge(vector<vector<int>> &adj, int s, int t){
    // Add edge from vertex s to t
    adj[s].push_back(t);
    adj[t].push_back(s);  //due to undirected graph
}

// recursive function for DFS traversal
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
    
    // mark the current vertex as visited
    visited[s] = true;

    // print the current vertex
    cout << s << " ";

    // recursively visit all adjacent vertices that are not visited yet
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited,i);
}

//function that initilizes the visited array and call DFSRec
void DFS(vector<vector<int>> &adj, int s){
    vector<bool> visited(adj.size(),false);

    //call recursive DFS Function
    DFSRec(adj, visited, s);
}

int32_t main(){

    int V = 5; //no. of vertices
    vector<vector<int>> adj(V);    //Adjacency list representation of the Graph

    // Define edges to the graph
    vector<vector<int>> edges = {{1,2}, {1,0}, {2,0}, {2,3}, {2,4}};

    //populate the adjacency list with edges
    for (auto &e : edges)
        addEdge(adj,e[0] , e[1]);

    int source = 1;  //starting vertex for DFS
    cout << "DFS from Source: " <<source << endl;
    DFS(adj,source); //perform Dfs starting from the source vertex

    return 0;
}