// Find the Missing Number

// Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the missing number from the first N integers.

// Note: There are no duplicates in the list

// Input: arr[] = {1, 2, 4, 6, 3, 7, 8} , N = 8
// Output: 5

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int MissingNumber(int n,vector<int>arr) {
    int sum = 0;
    // calculate the sum of array elements
    for(int i =0;i<n-1;i++) {
        sum+= arr[i];
    }

    // calculated the expected sum
    int expectedSum = (n*(n+1))/2;

    // return the missing number
    return expectedSum - sum;


}

int32_t main(){

    vector<int> arr = {1,2,3,4,6,7,8};
    int n = 8;
    cout<<"Missing number is: "<<MissingNumber(n, arr);
    return 0;
}