// Given a string s, find the length of the longest substring without repeating characters. 

// Input: “ABCBC”
// Output: 3

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int longestUniqueSubstr(string& s){
    int n = s.size();
    int res = 0;

    for (int i=0; i<n; i++) {

        // initilise all charactered are not visited9
        vector<bool> visited (256, false);

        for (int j=i; j<n; j++) {

            // if current character is visited break the loop
            if (visited[s[j]] == true)
                break;

            else {
                // update the result if this window is larger, and mark the currnet character as visited

                res = max(res, j - i + 1);
                visited[s[j]] = true;
            }
        }
    }
    return res;
}

int32_t main(){

    string s;
    cout << "enter the string: ";
    cin >> s;

    cout << "longest Unique Substring is: "<<longestUniqueSubstr(s);
    return 0;
}