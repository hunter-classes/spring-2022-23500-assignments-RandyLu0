#include "queue.h"

Queue::Queue(){
    vector<int> temp(size = 5);
    queue = temp;
    head = 0, tail = 0, empty = true, full = false; 
}

bool Queue::is_empty() const{ return empty; }

bool Queue::is_full() const{ return full; }

int Queue::front() const{
    if(is_empty()) throw std::out_of_range("Empty Queue");
    return queue[head];
}

int Queue::dequeue(){
    if(is_empty()) throw std::out_of_range("Queue Underflow");
    int t = front();
    empty = (head = (head + 1) % 5) == tail, full = 0;
    return t;
}

void Queue::enqueue(int d){
    if(is_full()) throw std::out_of_range("Queue Overflow");
    queue[tail] = d;
    full = (tail = (tail + 1) % 5) == head, empty = 0;
}