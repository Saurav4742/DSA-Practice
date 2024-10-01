// 1. Printing Boundary Elements of a Matrix:

// Given a matrix of size n x m. Print the boundary elements of the matrix. Boundary elements are those elements that are not surrounded by elements in all four directions, i.e. elements in the first row, first column, last row, and last column


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

const int MAX = 100;
void printBoundry(int a[][MAX],int m, int n){
    for (int i=0;i<m;i++) {
        for (int j =0;j<n;j++) {
            if (i ==0 || j==0 || i == m-1 || j == n-1)
            cout << a[i][j] << " ";
            else 
                cout << " " <<" ";
        }
        cout <<"\n";
    }
}

int getBoundarySum(int a[][MAX], int m, int n)
{
    long long int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0)
                sum += a[i][j];
            else if (i == m - 1)
                sum += a[i][j];
            else if (j == 0)
                sum += a[i][j];
            else if (j == n - 1)
                sum += a[i][j];
        }
    }
    return sum;
}

int32_t main(){

    int a[4][MAX] ={{1,2,3,4},
                    {5,6,7,8},
                    {1,2,3,4},
                    {5,6,7,8}};
    
    printBoundry(a,4,4);


    long long int sum = getBoundarySum(a, 4, 4);
    cout << "Sum of boundary elements is: " << sum;
    return 0;
}
// Input:  1 2 3 4  
//         5 6 7 8
//         1 2 3 4
//         5 6 7 8

// Output : 1 2 3 4 
//          5     8 
//          1     4 
//          5 6 7 8