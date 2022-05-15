#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "heap.h"

TEST_CASE("heapify operation"){

}

TEST_CASE("build"){
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++) arr[i] = SIZE - i;
    build(arr,SIZE);
    CHECK(is_heap(arr,SIZE));
}