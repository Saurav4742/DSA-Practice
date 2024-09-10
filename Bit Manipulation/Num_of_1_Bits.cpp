// Count set bits in an integer

// Write an efficient program to count the number of 1s in the binary representation of an integer.

// Input : n = 6
// Output : 2
// Binary representation of 6 is 110 and has 2 set bits



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unsigned int countSetBits( unsigned int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int32_t main(){
    // int i = 9;
    // cout << countSetBits(i);
    // return 0;

    int n;
    cout << "enter the number:";
    cin >> n;

    // handle the negative number
    if(n < 0) {
    cout <<"Negative numbers are not supported for counting set bits " << endl;
    }
    else {
    cout << "Number of set bits: "<<countSetBits(n);
    }
} 


/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// recursive function to count set bits
int countSetBits(int n)
{
    // base case
    if (n == 0)
        return 0;
    else
        // if last bit set add 1 else add 0
        return (n & 1) + countSetBits(n >> 1);
}
 

int main()
{
    int n = 9;
    
    cout << countSetBits(n);
    return 0;
}
*/
