// Number Of Islands

// Given a binary 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 4 islands.

// Input: M[][] = {{‘1’, ‘1’, ‘0’, ‘0’, ‘0’},
//                 {‘0’, ‘1’, ‘0’, ‘0’, ‘1’},
//                 {‘1’, ‘0’, ‘0’, ‘1’, ‘1’},
//                 {‘0’, ‘0’, ‘0’, ‘0’, ‘0’},
//                 {‘1’, ‘0’, ‘1’, ‘1’, ‘0’}}

// Output: 4

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

void DFS(vector<vector<char>>& M, int r, int c){
    int ROW = M.size();
    int COL = M[0].size();

    // base condition
    // if r or c is out of bounds or M[r][c] is not 1

    if (r < 0 || c < 0 || r>= ROW || c>=COL || M[r][c] != '1') {
        return ;
    }

    // mark the cell as visited by setting it to 0 
    M[r][c] = '0';

    // traverse all 8 possible directions
    vector<int> rNbr = {1, -1, 0, 0, 1, -1, 1, 1};
    vector<int> cNbr = {0, 0, 1, -1, 1, -1, -1, 1};

    for (int i = 0; i <8; i++) {
        int newR = r + rNbr[i];
        int newC = c + cNbr[i];
        DFS(M, newR, newC);
    }
}

//function to count the number of islands
int countIslands(vector<vector<char>>& M) {
    int ROW = M.size();
    int COL = M[0].size();
    int count = 0;

    // traverse the entire matrix
    for (int r = 0; r<ROW; r++) {
        for (int c = 0; c<COL;c++) {
            
            // If a cell with value 1 is found
            if (M[r][c] == '1') {

                // increment the island count
                count++;

                // start DFS from the current cell
                DFS(M, r, c);
            }
        }
    }
    return count;
}

int32_t main(){

    vector<vector<char>> M ={ { '0', '1', '0', '0', '1' },
                              { '1', '0', '0', '1', '1' },
                              { '0', '0', '0', '0', '0' },
                              { '1', '0', '1', '1', '0' } };

    cout <<"No of island: "<< countIslands(M) << endl;

    return 0;
}