#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "set.h"

TEST_CASE("Hash Table Operations"){
    
    Dictionary* d = new Dictionary();
    string name = "Randy Lu";
    CHECK(d->find(name) == nullptr);
    CHECK(d->keys() == "");
    Person* a = new Person(name, 0);
    Person* b = new Person(name, 1);
    d->insert(a);
    CHECK(d->keys() == "Randy Lu\n");
    d->insert(b);
    CHECK(d->keys() == "Randy Lu\nRandy Lu\n");
    CHECK(d->find(name)->get_id() != a->get_id());
    CHECK(d->find(name)->get_name() == a->get_name());
    CHECK(d->find(name)->get_id() == b->get_id());
    CHECK(d->find(name)->get_name() == b->get_name());

    delete a, a = nullptr;
    delete b, b = nullptr;
    delete d, d = nullptr;
}