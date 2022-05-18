#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "heap.h"

TEST_CASE("heapify and build"){
    const int size = 5;
    int a[size] = {1,5,4,3,2};
    int b[size] = {5,4,3,2,1};
    build(b,size);
    CHECK(is_heap(b,size));
    heapify(a, 0, size);
    CHECK(is_heap(a, size));
    for(int i = 0; i < size; i++) a[i] = size - i;
    for(int i = 0; i < size; i++) heapify(a, i, size);
    for(int i = 0; i < size; i++) CHECK(a[i] == size - i);
    build(a,size);
    CHECK(is_heap(a, size));
}

TEST_CASE("heapsort"){
    int a[SIZE];
    for(int i = 0; i < SIZE; i++) a[i] = i;
    heapsort(a, SIZE);
    for(int i = 0; i < SIZE; i++) CHECK(a[i] == i);
    for(int i = 0; i < SIZE; i++) a[i] = SIZE - (i + 1);
    heapsort(a, SIZE);
    for(int i = 0; i < SIZE; i++) CHECK(a[i] == i);
}