#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int
//There are no positive values less than zero so the data set cannot be arranged which counts as the possible combination of how data can be arranged(it cannot). Thus,0!=1.
int f(int n){
    if(n==0 ||n == 1)
    return 1;

    else
        return n*f(n-1);
}

int32_t main(){

    int n;
    cout<< "enter the number:" ;
    cin >> n;

    cout<< "factorial of "<<n<<" is:"<<f(n);
        return 0;
}