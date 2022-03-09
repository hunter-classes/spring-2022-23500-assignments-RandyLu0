#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "List.h"

OList *l = new OList();

TEST_CASE("insert"){
    l->insert("d");
    l->insert("c");
    l->insert("b");
    l->insert("a");
    l->insert("z");
    CHECK(l->toString() == "a->b->c->d->z->nullptr\n");
}

TEST_CASE("remove"){
    l->remove(-100);
    CHECK(l->toString() == "b->c->d->z->nullptr\n");
    l->remove(100);
    CHECK(l->toString() == "b->c->d->nullptr\n");
    l->remove(1);
    CHECK(l->toString() == "b->d->nullptr\n");
}

TEST_CASE("contains"){
    CHECK(l->contains("b"));
    CHECK(!l->contains("1"));
}


TEST_CASE("get"){
    CHECK(l->get(1) == "d");
    CHECK(l->get(-100) == "b");
    CHECK(l->get(100) == "d");
}

TEST_CASE("reverse"){
    l->reverse();
    CHECK(l->toString() == "d->b->nullptr\n");
    l->reverse();
    CHECK(l->toString() == "b->d->nullptr\n");
    delete l, l = nullptr;
}