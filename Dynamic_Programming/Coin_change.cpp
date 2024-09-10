// Coin Change – Count Ways to Make Sum

// Given an integer array of coins[ ] of size N representing different types of denominations and an integer sum, the task is to count all combinations of coins to make a given value sum.  

// Input: sum = 4, coins[] = {1,2,3}
// Output: 4
// Explanation: there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2} and {1, 3}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int count(vector<int>& coins,int n,int sum) {
    
    // 2d dp array where n is the number of coin ,sum is target sum
    vector<vector<int>> dp(n+1, vector<int>(sum+1,0));


    dp[0][0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=sum;j++) {
            

            // Add the number of ways to make change without using the current coin,
            dp[i][j] += dp[i - 1][j];

            if ((j-coins[i - 1]) >= 0) {
                
                // Add the number of ways to make change using the current coin
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[n][sum];

}

int32_t main(){

    vector<int> coins;
    int n, sum;
    cout<< "enter the number of coins : ";
    cin >> n;

    coins.resize(n);

    cout<<"enter the values of coin: ";
    for(int i=0;i<n;i++) {
    cin>>coins[i];
    }

    cout << "enter the sum: ";
    cin >>sum;
    
    cout<<count(coins,n,sum);
    return 0;
}