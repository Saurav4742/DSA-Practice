// Sort a nearly sorted (or K sorted) array

// Given an array of N elements, where each element is at most K away from its target position, devise an algorithm that sorts in O(N log K) time.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int

void Sortk(vector<int>&arr,int n ,int k) {
    // int size;
    int size = (n == k) ? k : k + 1;
    priority_queue<int, vector<int>,greater<int> > pq(arr.begin(), arr.begin()+min(k+1,n) );

    int index = 0;

    for (int i = k+1; i<n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }
}

void printArray(vector<int>&arr, int size){
    for (int i=0;i<size;i++)
        cout << arr[i] <<" ";
    cout <<endl;
}

int32_t main(){

    int n,k;
    cout<< "enter the size of array:" ;
    cin >> n;
    cout << "enter the k value:";
    cin>>k;

    cout << "enter the array:";
    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    
    Sortk(arr,n,k);
    cout<<"sort array is:";
    printArray(arr,n);
        return 0;
}
// Input: arr[] = {6, 5, 3, 2, 8, 10, 9}, K = 3 
// Output: arr[] = {2, 3, 5, 6, 8, 9, 10}