#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

unsigned int reverseBits(unsigned int n) {

    unsigned int rev = 0;
    while (n > 0) {
        // bitwise left shift 'rev' by 1

        rev <<= 1;
    
    // cout << " hello";

    // if currnet bit is 1
    if (n & 1 == 1) 
        rev ^= 1;

        // bitwise right shift 'n' by 1;
        n >>= 1;
    }

    // required number
    return rev;
}

int32_t main(){

    unsigned int n ;
    cout << "Enter the Number: ";
    cin >> n;

    cout << reverseBits(n);
    return 0;
}