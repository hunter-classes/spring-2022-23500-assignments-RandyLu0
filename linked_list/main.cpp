#include "List.h"
#include <iostream>

using std::cout;

int main(){
    
    /*
    Node *p1 = new Node("s");
    Node *p2 = new Node("t");
    p1->setNext(p2);
    cout << typeid(p1).name()  << "\n";
    cout << p1->getData() << "\n";
    delete p1, p1 = nullptr;
    delete p2, p2 = nullptr;
    */

    OList *l1 = new OList();
    l1->insert("d");
    l1->insert("c");
    l1->insert("b");
    l1->insert("a");
    cout << l1->toString();
    l1->remove(-200);
    cout << l1->get(-10) << "\n";
    cout << l1->toString();
    l1->reverse();
    cout << l1->toString();
    delete l1, l1 = nullptr;

    return 0;
}