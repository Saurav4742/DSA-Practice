// Snake and Ladder Problem

// Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from the source or 1st cell. Basically, the player has total control over the outcome of the dice throw and wants to find out the minimum number of throws required to reach the last cell.
// If the player reaches a cell which is the base of a ladder, the player has to climb up that ladder and if reaches a cell is the mouth of the snake, and has to go down to the tail of the snake without a dice throw.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

// entry in queue used in BFS
struct queueEntry {
    int v;   //vertex number
    int dist; //Dist of this vertex from source
}; 

int  getMinDiceThrows(int move[] , int N){
    bool* visited = new bool[N];
    for (int i =0;i<N;i++) {
        visited[i] = false;
    }

    // queue for BFS
    queue<queueEntry> q;

    // mark the node 0 as visited and enqueue it.
    visited[0] = true;
    queueEntry s = {0,0};   //start point
    q.push(s);     //Enqueue 0'th vertex.

    // Do a BFS starting from vertex at index 0
    queueEntry qe;  // queue entry(qe)
    while (!q.empty()) {
        qe = q.front();
        int v = qe.v;  

        if (v == N-1)
            break;

        q.pop();
        for (int j = v+1;j<= (v+6) && j<N;++j) {
            if (!visited[j]) {
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;

                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
    return qe.dist;
}

int32_t main(){
    // board construction
    int N=30;
    int moves[N];
    for (int i=0;i<N;i++) {
        moves[i] =-1;
    }

    // ladders
    moves[2] = 21;
    moves[4] = 9;
    moves[10] = 25;
    moves[19] = 28;

    // snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout <<"Min Dice throws required is: "<< getMinDiceThrows(moves,N);

    return 0;
}