#ifndef STACK_H
#define STACK_H
#pragma once

#include "list.h"

class Stack{
    private:
        List *stack;
        int size;
    public:
        Stack();
        ~Stack();
        void push(int d);
        int pop();
        int top() const;
        bool is_empty() const;
};

#endif