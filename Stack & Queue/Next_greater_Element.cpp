// Next Greater Element (NGE) for every element in given Array

// Input: arr[] = [ 4 , 5 , 2 , 25 ]
// Output:  4  –> 5
//          5  –> 25
//          2  –> 25
//          25 –> -1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int
void printNGE(const vector<int>& arr){
    stack<int>s;
    int n = arr.size();

    for(int i = 0;i<n;i++) {
        
        if(s.empty()) {
            s.push(arr[i]);
            continue;
        }
        while(!s.empty() && s.top() < arr[i]) {
            cout << s.top() << "--> " <<arr[i] <<endl;
            s.pop();
        }
        s.push(arr[i]);
    }

    while (!s.empty()) {
        cout << s.top() <<"-->" <<-1 <<endl;
        s.pop();
    }
}
        
int32_t main(){

int n;
cout<<"enter the size of array: ";
cin>>n;

vector<int>arr(n);

cout<<"enter " <<n <<" elements of the array:" <<endl;
for(int i=0;i<n;i++) {
    cin>>arr[i];
}
printNGE(arr);
// int arr[] = {11 , 13, 21,3};
// int n = sizeof(arr)/sizeof(arr[0]);
// printNGE(arr , n);

    return 0;
}