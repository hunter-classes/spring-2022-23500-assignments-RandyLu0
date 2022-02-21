#include "Node.h"
//#include "List.h"
#include <iostream>
#include <memory>
using std::cout;
using std::unique_ptr;

int main(){
    unique_ptr<Node> p1 (new Node("s"));
    unique_ptr<Node> p2 (new Node("t"));
    p1->setNext(p2);
    cout << typeid(p1).name()  << "\n";
    cout << p1->getData() << "\n";
    return 0;
}