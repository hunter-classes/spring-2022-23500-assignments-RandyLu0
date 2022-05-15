#include "heap.h"

#include <bits/stdc++.h>
using namespace std;

//maintains max-heap property
void heapify(int arr[], int i, int size){
    int max, mi, l = 2*i+1, r = 2*i+2;
    if(r >= size and l >= size) return;
    if(r >= size) max = MAX2(arr[i],arr[l]);
    else max = MAX3(arr[i], arr[l], arr[r]);
    mi = max == arr[l] ? l : max == arr[r] ? r : i;
    if(mi != i){
        SWAP(arr[mi],arr[i]);
        heapify(arr,mi,size);
    }
}

//builds a max-heap from an array
void build(int arr[], int size){
    //leaves are heaps
    for(int i = size / 2 - 1; i >= 0; i--) heapify(arr, i, size);
}

//sorts an array into ascending order by heapsort
void heapsort(int arr[], int size){
    build(arr,size);
    for(int i = 1; i < size; i++){
        SWAP(arr[0],arr[size-i]);
        heapify(arr, 0, size-i);
    }
}

//checks if array is max-heap
bool is_heap(int arr[], int size){
    int l, r, max;
    for(int i = 0; i < size / 2 - 1; i++){
        l=2*i+1, r=2*i+2, max= r>=SIZE ? MAX2(arr[i],arr[l]) : MAX3(arr[i],arr[l],arr[r]);
        if(max != arr[i]) return false;
    } return true;
}
