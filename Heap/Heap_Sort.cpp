// Heap Sort 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define int long long int

void heapify(vector<int>&arr,int n, int i) {
    int largest = i; // initilise the kargest as root
    int l = 2*i+1;  //left
    int r = 2*i+2;  //right

    if (l<n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if(largest!=i) {
        swap(arr[i],arr[largest]);

        heapify(arr,n,largest);
    }
}

void heapsort(vector<int>&arr,int n) {
    for (int i=n/2-1;i>=0;i--) //build heap(rearrange array)
        heapify(arr,n,i);

    for (int i=n-1;i>0;i--) {
        swap (arr[0],arr[i]); //move current root to end

        heapify(arr,i,0); //call max heapify on the reduced heap
    }
}


void printArray(vector<int>&arr,int n){
    for (int i=0;i<n;i++)
        cout <<arr[i] <<" ";
    cout <<endl;
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
heapsort(arr,n);
cout << "Sorted array is: \n";
printArray(arr, n);
    return 0;
}
