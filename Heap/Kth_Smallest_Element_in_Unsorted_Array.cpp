// K’th Smallest Element in Unsorted Array

// Given an array arr[] of N distinct elements and a number K, where K is smaller than the size of the array. Find the K’th smallest element in the given array.

// [Expected Approach] Using Priority Queue(Max-Heap) – O(N * log(K)) time and O(K) auxiliary space:

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>&arr, int N, int K)
{
    // Create a max heap (priority queue)
    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {     //iterate
        // Push the current element onto the max heap
        pq.push(arr[i]);

        // If the size of the max heap exceeds K, remove the largest element
        if (pq.size() > K)
            pq.pop();
    }

    // Return the Kth smallest element (top of the max heap)
    return pq.top();
}

// Driver's code:
int main()
{
    int n ,k;
cout<<"size of array: " ;
cin >>n;
cout<<"element no:";
cin>>k;
cout <<"enter the array: ";
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin >>arr[i];
}

    // Function call
    if (k<=n && k>=0){
    cout <<k<<"th Smallest Element is: "
         << kthSmallest(arr, n, k);
    }
    else if(k>n){
        cout<<"element no. is more then size of array";
    }
    else 
    cout<<"negative element no.";
}

// Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3 
// Output: 7
