#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bstree.h"
using std::out_of_range;

BSTree *b = new BSTree();
TEST_CASE("Binary Search Tree Operations"){
    CHECK_THROWS_AS(b->remove(0), out_of_range);
    CHECK_THROWS_AS(b->rsearch(0), out_of_range);
    b->insert(2); b->insert(0); b->insert(4);
    CHECK_THROWS_AS(b->rsearch(-1), out_of_range);
    CHECK_THROWS_AS(b->remove(-1), out_of_range);
    for(int i = 0; i < 6; i += 2) CHECK(b->rsearch(i) == i);
    for(int i = 0; i < 6; i += 2) b->remove(i);
    for(int i = 0; i < 6; i += 2) CHECK_THROWS_AS(b->rsearch(i), out_of_range);
}

TEST_CASE("Binary Search Tree Routines"){
    CHECK_THROWS_AS(b->levelsum(0), out_of_range);
    CHECK(b->height() == 0);
    CHECK(b->leaves() == 0);
    b->insert(2); 
    CHECK(b->height() == 0);
    b->insert(1); 
    CHECK(b->height() == 1);
    CHECK(b->leaves() == 1);
    CHECK_THROWS_AS(b->levelsum(-1), out_of_range);
    CHECK_THROWS_AS(b->levelsum(100), out_of_range);
    CHECK(b->levelsum(0) == 2);
    CHECK(b->levelsum(1) == 1);
    b->insert(4);
    CHECK(b->levelsum(1) == 5   );
    CHECK(b->height() == 1);
    b->remove(1);
    CHECK(b->height() == 1);
    CHECK(b->levelsum(1) == 4);
    delete b, b = nullptr;
}



