#include "Node.h"
//#include "List.h"
#include <iostream>
using std::cout;

int main(){
    Node *p1 = new Node("s");
    Node *p2 = new Node("t");
    p1->setNext(p2);
    cout << p1->getNext()->getData() << "\n";
    return 0;
}