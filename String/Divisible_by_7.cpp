// Check divisibility by 7

// Given a number N, the task is to check if it is divisible by 7 or not.


// Divisibility by 7 can be checked by a recursive method. A number of the form 10a + b is divisible by 7 if and only if a – 2b is divisible by 7. In other words, subtract twice the last digit from the number formed by the remaining digits. Continue to do this until a small number. 


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int isDivisibleBy7(int n) 
{
    if (n<0)
        return isDivisibleBy7(-n);

    if (n==0 || n==7)
        return 1;
    if(n<10)
        return 0;
    return isDivisibleBy7(n/10-2*(n-n/10*10));
    
}

int32_t main(){

int n;
cout<< "enter the number:" ;
cin >> n;
if(isDivisibleBy7(n))
    cout << "Divisible";
else
    cout << "Not Divisible";
    return 0;
}