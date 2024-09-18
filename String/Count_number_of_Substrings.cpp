// Count number of substrings with exactly k distinct characters

// Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that has exactly k distinct characters. 


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int countkDist(string str, int k) {
    int n = str.length();

    int res = 0;

    int cnt[26];

    for (int i=0;i<n;i++) {
        int dist_count = 0;

        memset(cnt,0,sizeof(cnt));

        for(int j=i;j<n;j++) {

            if (cnt[str[j] - 'a'] == 0)
                dist_count++;

        cnt[str[j] - 'a']++;

        if (dist_count == k)
            res++;

        if (dist_count > k) break;
        }
    }
    return res;
    
}

int32_t main(){

    string str;
    cout <<"Enter the String: ";
    cin >> str;
    int k;
    cout<< "enter the length of substring: " ;
    cin >> k;

    cout << "Total substring with exactly "<<k<<" distinct characters :"<<countkDist(str, k) <<endl;
    return 0;
}
// Input: abc, k = 2
// Output: 2
// Possible substrings are {“ab”, “bc”}