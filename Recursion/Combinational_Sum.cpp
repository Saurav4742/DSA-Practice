// Combinational Sum


// Given an array of positive integers arr[] and an integer x, The task is to find all unique combinations in arr[] where the sum is equal to x. 
// The same repeated number may be chosen from arr[] an unlimited number of times. Elements in a combination (a1, a2, …, ak) must be printed in non-descending order. (ie, a1 <= a2 <= … <= ak). If there is no combination possible print “Empty”

// Input: arr[] = 2, 4, 6, 8, x = 8
// Output: 
// [2, 2, 2, 2]
// [2, 2, 4]
// [2, 6]
// [4, 4]
// [8]

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// #define int long long int


void findNumbers(vector<int>& ar, int sum, vector<vector<int>>& res, vector<int>& r, int i) {

    // if we get exact answer
    if (sum == 0) {
        res.push_back(r);
        return;
    }

    // Recur for all remaining elements that have value smaller than sum.
    while (i<ar.size() && sum - ar[i] >= 0) {

        // jab tak array se sum me contribute kar raha hai usko list kiya hai
        r.push_back(ar[i]);

        // recursive call for next numbers
        findNumbers(ar, sum - ar[i], res, r , i);
        i++;

        // remove number from list (backtracking)
        r.pop_back();
    }
}

// Returns all combinations  of ar[] that have given sum.
vector<vector<int>> CombinationSum(vector<int>& ar, int sum) {
     
    sort(ar.begin(),ar.end());   //sort the input array

    // remove duplicate
    ar.erase(unique(ar.begin(),ar.end()), ar.end());

    vector<int> r;
    vector<vector<int>> res;
    findNumbers(ar, sum, res, r, 0);

    return res;
}

int32_t main(){

    int n, sum;
    cout<< "enter the number of element: ";
    cin >> n;

    vector<int> arr(n);
    // arr.resize(n);
    cout << "enter the array: ";
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << "enter the sum: ";
        cin >> sum;

    vector<vector<int>> res = CombinationSum(arr, sum);

    if (res.size() == 0) { // if result is empty
        cout << "empty";
        return 0;
    }


    // print all combination
    cout<<"total possible combination: "<<res.size()<<endl;
    for(auto x:res){
        for(auto y :x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }


    /* ye wala bhi pura combination print karega*/
    // for (int i =0; i <res.size(); i++) {
    //     if (res[i].size() > 0) {
    //         cout << " ( ";
    //         for (int j =0;j<res[i].size();j++)
    //             cout<< res[i][j] <<" ";
    //         cout << ")";
    //     }
    // }
    return 0;
}