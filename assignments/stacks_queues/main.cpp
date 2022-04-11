#include "stack.h"
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
    
    delete s, s = nullptr;
    return 0;
}