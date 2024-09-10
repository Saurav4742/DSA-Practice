// Container with Most Water

// Given n non-negative integers a_1, a_2, ..., a_n                  where each represents a point at coordinate (i, a_i)                  . ‘ n ‘ vertical lines are drawn such that the two endpoints of line i is at (i, a_i)                  and (i, 0)                  . 
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
// The program should return an integer which corresponds to the maximum area of water that can be contained (maximum area instead of maximum volume sounds weird but this is the 2D plane we are working with for simplicity).



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

int maxArea(int A[], int len) {
    int area = 0;
    for (int i=0; i<len; i++) {
        for (int j = i+1; j < len; j++) {
            // calculating the max area
            area = max(area, min(A[j], A[i])*(j-i));
        }
    }
    return area;
}

int32_t main(){

    int a[] = { 1,5,4,3};
    int b[] = {3,1,2,4,5};

    int len1 = sizeof(a)/sizeof(a[0]);
    cout << maxArea(a, len1);

    int len2 = sizeof(b)/sizeof(b[0]);
    cout << endl << maxArea(b, len2);

    return 0;
}


// Input: array = [1, 5, 4, 3]
// Output: 6
// Explanation : 
// 5 and 3 are distance 2 apart. 
// So the size of the base = 2. 
// Height of container = min(5, 3) = 3. 
// So total area = 3 * 2 = 6