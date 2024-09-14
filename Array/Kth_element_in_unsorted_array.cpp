// K’th Smallest Element in Unsorted Array

// Given an array arr[] of N distinct elements and a number K, where K is smaller than the size of the array. Find the K’th smallest element in the given array.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

int kthSmallest(vector<int>&arr , int n, int k){
    sort (arr.begin(), arr.end());
    return arr[k-1];
}

int32_t main(){

int n ,k;
cout<<"size of array: " ;
cin >>n;
cout<<" element no:";
cin>>k;
cout<<"enter the array: ";
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin >>arr[i];
}

    if (k<=n && k>=0){
    cout <<k<<"th Smallest Element is: "
         << kthSmallest(arr, n, k);
    }
    else if(k>n){
        cout<<"element no. is more then size of array";
    }
    else 
    cout<<"negative element no.";
    return 0;
}



// Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3 
// Output: 7