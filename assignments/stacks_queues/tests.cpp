#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stack.h"
#include "queue.h"
using std::out_of_range;

TEST_CASE("Stack operations"){
    Stack *s = new Stack();
    CHECK_THROWS_AS(s->pop(), out_of_range);
    CHECK_THROWS_AS(s->pop(), out_of_range);
    CHECK(s->is_empty());
    s->push(1), s->push(2);
    CHECK(s->top() == 2);
    CHECK(s->pop() == 2);
    CHECK(!s->is_empty());
    CHECK(s->pop() == 1);
    delete s, s = nullptr;

}

TEST_CASE("Queue operations"){
    Queue *q = new Queue();
    CHECK_THROWS_AS(q->dequeue(), out_of_range);
    CHECK_THROWS_AS(q->front(), out_of_range);
    CHECK(q->is_empty());
    CHECK(!q->is_full());
    for(int i = 0; i < 5; i++) q->enqueue(i);
    CHECK_THROWS_AS(q->enqueue(99), out_of_range);
    CHECK(q->is_full());
    CHECK(!q->is_empty());
    CHECK(q->front() == 0);
    CHECK(q->dequeue() == 0);
    q->enqueue(5);
    for(int i = 1; i < 6; i++) CHECK(q->dequeue() == i);
    CHECK_THROWS_AS(q->dequeue(), out_of_range);
    CHECK(q->is_empty());

    delete q, q = nullptr;
}



