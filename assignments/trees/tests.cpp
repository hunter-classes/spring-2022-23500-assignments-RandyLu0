#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bstree.h"
using std::out_of_range;

TEST_CASE("Binary Search Tree Operations"){
    BSTree *b = new BSTree();
    b->insert(2); b->insert(0); b->insert(4);
    for(int i = 0; i < 6; i += 2) CHECK(b->rsearch(i) == i);
    CHECK(b->height() == 2);
    CHECK(b->leaves() == 2);
    CHECK(b->levelsum(0) == 2);
    CHECK(b->levelsum(1) == 4);

    delete b, b = nullptr;

}



