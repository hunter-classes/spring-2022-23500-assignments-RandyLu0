#include "stack.h"
#include "queue.h"
#include <iostream>
using std::cout;

int main(){
    Stack *s = new Stack();
    s->push(1);
    cout << s->top() << "\n" << s->pop() << "\n" << s->is_empty() << "\n";
    try
    {
        s->pop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Queue *q = new Queue();
    for(int i = 0; i < 5; i++) q->enqueue(i);
    q->dequeue();
    q->enqueue(90);
    for(int i = 0; i < 5; i++) cout << q->dequeue() << "\n";
    cout << q->is_empty() << q->is_full() << "\n";
    delete q, q = nullptr;
    delete s, s = nullptr;
    return 0;
}