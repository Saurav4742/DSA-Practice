// Print adjacency list


// Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> S(V);
        for(auto x : edges){
            S[x.first].push_back(x.second);
            S[x.second].push_back(x.first);
        }
        return S;
    }
};

int main() {
        int V, E;
        cout<<"enter the vertex: ";
        cin >> V;
        cout<<"enter the number of edges: ";
        cin >> E;
        vector<pair<int,int>>edges;
        cout<<"enter the edges:";
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    return 0;
}


// Input:
// V = 5, E = 7
// edges = {(0,1),(0,4),(4,1),(4,3),(1,3),(1,2),(3,2)}

// Output: 
// {{1,4}, 
//  {0,2,3,4}, 
//  {1,3},
//  {1,2,4},
//  {0,1,3}}