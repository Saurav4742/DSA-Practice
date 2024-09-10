// Dynamic Programming (Bottom Up) Solution:

// Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. We are mainly given a price array such that the size of the price array is same as rod length and price[i] represents price of length i+1


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

int cutRod (vector<int>&price, int length) {
    // create a dp array to store the maximum revenue obtainable for each length
    vector<int> dp(length+1, 0 );

    // build a dp array in a bottom-up manner
    for(int i =1; i<=length;i++) {
        int max_val = 0;
        for (int j=0;j<i;j++) {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }
    return dp[length];
}

int32_t main(){

    int length;
    cout<< "enter the length of rod: ";
    cin >> length;

    vector<int>price(length);
    cout<<"enter the price for each length: ";
    for (int i=0;i<length;i++){
        cin>>price[i];
    }

    cout<< cutRod (price,length);
    return 0;
}
// Input : price[] = { 1 , 5, 8, 9, 10, 17 , 17 , 20}
// Output : 22
// Explanation : Rod length is 8 and the values of different pieces are given as the following,
// length | 1 2 3 4 5 6 7 8
// ——————————
// price | 1 5 8 9 10 17 17 20
// The maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)