// Rod Cutting

// Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. We are mainly given a price array such that the size of the price array is same as rod length and price[i] represents price of length i+1



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

int  MaximumObtainableValue(vector<int>&price , int length) {
    //base case
    if (length <= 0) {  //if length is 0 then we cannot the rod
        return 0;
    }

    int res = 0;
    for (int i=0;i<length;i++){
        res = max( res,price[i] + MaximumObtainableValue(price, length-i-1) );

    }
    return res;
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

    cout<< MaximumObtainableValue(price,length);
    return 0;
}
// Input : price[] = { 1 , 5, 8, 9, 10, 17 , 17 , 20}
// Output : 22
// Explanation : Rod length is 8 and the values of different pieces are given as the following,
// length | 1 2 3 4 5 6 7 8
// ——————————
// price | 1 5 8 9 10 17 17 20
// The maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)