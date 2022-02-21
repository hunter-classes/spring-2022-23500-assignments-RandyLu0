#include "List.h"
#include <iostream>

using std::cout;

int main(){
    Node *p1 = new Node("s");
    Node *p2 = new Node("t");
    p1->setNext(p2);
    cout << typeid(p1).name()  << "\n";
    cout << p1->getData() << "\n";
    delete p1;
    delete p2;

    List *l1 = new List();
    l1->insert(0,"p");
    l1->insert(1,"q");
    l1->insert(1,"r");
    l1->remove(2);
    cout << l1->toString();
    delete l1;

    return 0;
}