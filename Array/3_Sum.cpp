// 3 Sum – Find All Triplets with Zero Sum

// Given an array of distinct elements. The task is to find triplets in the array whose sum is zero.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<vector<int>> findTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    int n = arr.size();

    // loop to find the triplets
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n-1 ;j++){
            for(int k=j+1; k<n; k++) {

                // triplet check karne ke liye sum zero hai ya nahi
                if (arr[i] + arr[j] +arr[k] == 0) {

                    // if sum is zero , store the triplet in the vector
                    triplets.push_back({arr[i], arr[j], arr[k]});
                }
            }
        }
    }
    return triplets;
}

int32_t main(){

    int n;
    cout<< "enter the size: " ;
        cin >> n;

    vector<int>arr(n);
    cout<< "enter the number: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    vector<vector<int>> result = findTriplets(arr);

    if (result.empty()) {
        cout << "No Triplet found with sum Zero.";
    }
    else {
        for (auto &t : result) {
            cout << t[0] <<", "<< t[1] << ", " << t[2] <<endl;
        }
    }
    return 0;
}
// Input: arr[] = {0, -1, 2, -3, 1}
// Output: [[0, -1, 1], [2, -3, 1]]
// Explanation: The triplets with zero sum are 0 + -1 + 1 = 0 and 2 + -3 + 1 = 0 