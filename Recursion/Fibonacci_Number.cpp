#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int fibonacci_numbers(int n){
    if(n == 0) {
        return 0;
    }
    else if(n==1) {
        return 1;
    }
    else {
        return fibonacci_numbers(n-2) + fibonacci_numbers(n-1);
    }
}

int32_t main(){

    int n;
    cout<< "enter the number: ";
    cin >> n;

    for(int i=0;i<n;i++) {
        cout << fibonacci_numbers(i) <<" ";
    }
        return 0;
}