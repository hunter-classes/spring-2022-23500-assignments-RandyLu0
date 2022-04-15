#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <stdexcept>
using std::vector;

class Queue{
    private:
        vector<int> queue;
        int size;
        int head, tail;
        bool empty, full;
    public:
        Queue();
        void enqueue(int d);
        int dequeue();
        int front() const;
        bool is_empty() const;
        bool is_full() const;
};

#endif