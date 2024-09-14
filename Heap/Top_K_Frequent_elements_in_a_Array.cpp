// Top K Frequent Elements in an Array

// Given an array of n numbers and a positive integer K. The problem is to find K numbers with the most occurrences. If two numbers have the same frequency then the number with a larger value should be given preference. The numbers should be displayed in decreasing order of their frequencies. It is assumed that the array consists of at least K numbers.



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

bool compare(pair<int,int>p1, pair<int,int>p2) {
    if (p1.second == p2.second)
        return p1.first>p2.first;

    return p1.second > p2.second;
}


void topKFrequent(vector<int>&arr,int n, int k){
    unordered_map<int,int> mp;
    for (int i =0;i<n;i++) {
        mp[arr[i]]++;
    }

    vector<pair<int,int>> freq_arr(mp.begin(),mp.end());  //store the elements of mp in vector'freq_arr'

    sort(freq_arr.begin(),freq_arr.end(),compare);

    cout << k <<"numbers with most occurrences are:"<<endl;

    for(int i=0;i<k;i++) {
        cout << freq_arr[i].first << " ";
    }
}

int32_t main(){

    int n ,k;
    cout<<"size of array: " ;
    cin >>n;
    cout<<"more occurance number:";
    cin>>k;
    cout<<"enter the array: ";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }

    // if (k<=n && k>=0){
    // cout <<"top"<<k<< "frequent is: "<<
        topKFrequent(arr, n, k);
    // }
    // else if(k>n){
    //     cout<<"element no. is more then size of array";
    // }
    // else 
    // cout<<"negative element no.";
    return 0;
}



// Input: arr[] = {3, 1, 4, 4, 5, 2, 6, 1}, K = 2
// Output: 4 1
// Explanation:
// Frequency of 4 = 2, Frequency of 1 = 2
// These two have the maximum frequency and 4 is larger than 1