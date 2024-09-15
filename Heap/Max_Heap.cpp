// Convert Min Heap to Max Heap

// Given an array representation of min Heap, convert it to max Heap.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int
void swap(int*a, int* b) {
    int temp =*a;
    *a =*b;
    *b = temp;
}

void maxHeapify(vector<int>&arr,int i,int n) {
    int l=2*i+1;
    int r=2*i+2;
    int largest = i;

    if (l<n && arr[l] > arr[i])
        largest = l;
    if (r<n && arr[r] > arr[largest])
        largest = r;
    if (largest!= i) {
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr, largest,n);
    }
}


void convertMaxHeap(vector<int>&arr, int n) {
    for(int i=(n-2)/2;i>=0;--i)
        maxHeapify(arr,i,n);
}

// void minHeapify(vector<int>&arr,int i,int n) {
//     int l=2*i+1;
//     int r=2*i+2;
//     int smallest = i;

//     if (l<n && arr[l] < arr[i])
//         smallest = l;
//     if (r<n && arr[r] < arr[smallest])
//         smallest = r;
//     if (smallest!= i) {
//         swap(&arr[i],&arr[smallest]);
//         minHeapify(arr, smallest,n);
//     }
// }


// void convertMinHeap(vector<int>&arr, int n) {
//     for(int i=(n-2)/2;i>=0;--i)
//         minHeapify(arr,i,n);
// }

void printArray(vector<int>&arr,int size){
    for(int i=0;i<size;i++)
    cout<<arr[i] << " ";
}

int32_t main(){

    int n;
    cout<< "enter the size of array: " ;
    cin >> n;

    cout<<"enter the array: ";
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // convertMinHeap(arr,n);
    // cout<<"min Heap Array : ";
    // printArray(arr,n);
    // cout<<endl;

    convertMaxHeap(arr,n);
    cout<<"max Heap Array : ";
    printArray(arr,n);

    return 0;
}
// Input: arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9}

//                3
//              /   \
//            5       9
//         /   \     /  \
//       6      8   20   10
//     /  \    /
//    12  18  9 

// Output: arr[] = {20, 18, 10, 12, 9, 9, 3, 5, 6, 8}
//                20
//              /   \
//            18      10
//         /   \     /  \
//       12     9   9    3
//     /  \    /
//    5    6  8 