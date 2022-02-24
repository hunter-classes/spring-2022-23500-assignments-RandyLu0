#include "List.h"
#include <iostream>

using std::cout;

int main(){
    
    Node *p1 = new Node("s");
    Node *p2 = new Node("t");
    p1->setNext(p2);
    cout << typeid(p1).name()  << "\n";
    cout << p1->getData() << "\n";
    delete p1, p1 = nullptr;
    delete p2, p2 = nullptr;

    List *l1 = new List();
    l1->insert(0,"a");
    l1->insert(1,"b");
    l1->insert(1,"c");
    l1->insert(3,"d");
    l1->remove(2);
    cout << l1->toString();
    l1->reverse(nullptr,l1->locate(0));
    cout << l1->toString();
    l1->insert(0,"z");
    l1->sort(0,3);
    cout << l1->toString();
    delete l1, l1 = nullptr;

    return 0;
}