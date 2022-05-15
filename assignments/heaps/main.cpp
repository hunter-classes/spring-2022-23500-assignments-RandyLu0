#include "heap.h"
#include <iostream>
using std::cout;

int main(){
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++) arr[i] = SIZE - i;
    build(arr,SIZE);
    for(auto c : arr) cout << c << " "; 
    cout << "\n" << is_heap(arr,SIZE) << "\n";
    return 0;
}