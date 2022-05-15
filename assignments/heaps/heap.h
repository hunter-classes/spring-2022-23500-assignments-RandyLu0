#pragma once
#ifndef HEAP_H

#define SIZE 8
#define MAX3(a,b,c) a >= b and a >= c ? a : b >= c and b >= a ? b : c 
#define MAX2(a,b) a > b ? a : b
#define SWAP(a,b) a += b, b = a - b, a -= b

void heapify(int arr[], int i, int size);
void build(int arr[], int size);
void heapsort(int arr[], int size);
bool is_heap(int arr[], int size);

#endif