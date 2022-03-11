#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "List.h"

OList *l = new OList();

TEST_CASE("insert"){
    l->insert("d");
    CHECK(l->toString() == "d->nullptr\n");
    l->insert("c");
    CHECK(l->toString() == "c->d->nullptr\n");
    l->insert("b");
    l->insert("a");
    l->insert("z");
    CHECK(l->toString() == "a->b->c->d->z->nullptr\n");
}

TEST_CASE("remove"){
    OList *g = new OList();
    CHECK_THROWS_AS(g->remove(1), std::out_of_range);
    l->remove(-100);
    CHECK(l->toString() == "b->c->d->z->nullptr\n");
    l->remove(100);
    CHECK(l->toString() == "b->c->d->nullptr\n");
    l->remove(1);
    CHECK(l->toString() == "b->d->nullptr\n");
    delete g, g = nullptr;
}

TEST_CASE("contains"){
    OList *g = new OList();
    CHECK(!g->contains("1"));
    CHECK(l->contains("b"));
    CHECK(!l->contains("1"));
    delete g, g = nullptr;
}


TEST_CASE("get"){
    OList *g = new OList();
    REQUIRE_THROWS_AS(g->get(1), std::out_of_range);
    CHECK(l->get(1) == "d");
    CHECK(l->get(-100) == "b");
    CHECK(l->get(100) == "d");
    delete g, g = nullptr;
}

TEST_CASE("reverse"){
    OList *g = new OList();
    g->reverse();
    CHECK(g->toString() == "nullptr\n");
    l->reverse();
    CHECK(l->toString() == "d->b->nullptr\n");
    l->reverse();
    CHECK(l->toString() == "b->d->nullptr\n");
    delete l, l = nullptr;
    delete g, g = nullptr;
}