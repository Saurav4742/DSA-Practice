// Find duplicates

// Given an array of n elements that contains elements from 0 to n-1, with any of these numbers appearing any number of times. Find these repeating numbers in O(n) and use only constant memory space.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> findDuplicates(vector<int> &num){
    int n= num.size();
    vector<int> arr(n+1,0);

    vector<int>list;

    for(int i:num) {
        if(++arr[i] > 1)
        list.push_back(i);
    }
    return list;
}

int32_t main(){

vector<int> num = {4,3,2,7,8,2,3,1};
vector<int> duplicates = findDuplicates(num);

// print the duplicates
cout<<"Duplicate Element are ";
for(int num : duplicates) {
    cout << num << " ";
}
cout << endl;
    return 0;
}