// The Celebrity Problem

// Given a square matrix M[][] of size N X N, such that M[i][j] = 1 means ith person knows jth person, the task is to find the celebrity. A celebrity is a person who is known to all but does not know anyone. Return the index of the celebrity, if there is no celebrity return -1.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

bool knows(int a,int b,vector<vector<int> >&matrix){
    return matrix[a][b];
}

int findCelebrity(int n, vector<vector<int>>&matrix) {
    stack<int>s;

    int C;

    for (int i=0; i<n; i++)
        s.push(i);


    while (s.size() > 1) {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        if (knows(A,B,matrix)) {
            s.push(B);
        }
        else {
            s.push(A);
        }
    }

    C = s.top();
    s.pop();

    for (int i=0;i<n;i++) {

        if( (i!=C) && (knows(C,i,matrix) || !knows(i,C,matrix)))

        return -1;
    }
    return C;
}

int32_t main(){

    int n = 4;
    vector<vector<int> > matrix= { { 0, 0, 1, 0},
                                    {0, 0, 1, 0},
                                    {0, 0, 0, 0},
                                    {0, 0, 1, 0} };

    int id = findCelebrity(n, matrix);
    if(id== -1)
        cout << "No CCelebrity";
    else
        cout << "Celebrity ID: " <<id;

    return 0;
}


// Input: MATRIX = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} }
// Output: id = 2
// Explanation: The person with ID 2 does not know anyone but everyone knows him