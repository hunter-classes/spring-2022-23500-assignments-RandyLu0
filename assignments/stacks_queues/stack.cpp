#include "stack.h"

Stack::Stack(){ stack = new List(); size = 0; }

Stack::~Stack(){ delete stack, stack = nullptr; }

bool Stack::is_empty() const{ return size == 0; }

int Stack::top() const{ 
    if(size == 0) throw std::out_of_range("Empty Stack");
    return stack->get(0); 
}

int Stack::pop(){
    if(size == 0) throw std::out_of_range("Stack Underflow");
    int temp = top();
    stack->remove(0), --size;
    return temp;
}

void Stack::push(int d){ stack->insert(0,d), ++size; }