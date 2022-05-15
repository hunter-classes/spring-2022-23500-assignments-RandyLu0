#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "set.h"

TEST_CASE("Hash Table Operations"){
    Dictionary *d = new Dictionary();
    
    delete d, d= nullptr;
}