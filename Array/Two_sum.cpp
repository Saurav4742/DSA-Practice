// Pair with given Sum


// Given an array arr[] of n integers and a target value, the task is to find whether there is a pair of elements in the array whose sum is equal to target if yes result is 1 else 0


/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

bool twosum(vector<int>&arr , int target){
    int n =arr.size();

    for(int i= 0;i<n;i++) {
        for(int j=i+1;j<n;j++){

            if(arr[i] + arr[j] == target) 
            return true;
        }
    }
    return false;
}

int32_t main(){
    vector<int>arr={0,-1,2,-3,1};
    int target = -2;
    cout<<twosum(arr,target);
    return 0;
}
*/

// [Better Approach] Using HashSet – O(n) time and O(n) space
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

bool twosum(vector<int>&arr , int target){
    
    // create a unordered set to store the element
    unordered_set<int> s;

    // iterate through array
    for(int i=0; i<arr.size();i++) {

        // Calculate the complement that added to
        // arr[i], equals the target
        int complement = target - arr[i];

        if(s.find(complement) != s.end()) {
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

int32_t main(){
    int n , target;
    cout << " enter the size of the array: ";
    cin >> n;

    vector<int>arr(n);
    cout<<"enter the array: ";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout << "enter the target value: ";
    cin >> target;
    // vector<int>arr={0,-1,2,-3,1};
    // int target = -2;
    cout<<twosum(arr,target);
    return 0;    
}