#include "List.h"
#include <iostream>
#include <exception>

using std::cerr;
using std::cout;
using std::exception;

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
    try{
        l1->get(1);
    }catch(const exception& e){
        cerr << e.what();
    }
    try{
        l1->remove(1);
    } catch(const exception& e){
        cerr << e.what();
    }
    l1->insert("d");
    l1->insert("c");
    l1->insert("b");
    l1->insert("a");
    l1->insert("z");
    l1->insert("d");
    cout << l1->toString();
    l1->remove(2);
    cout << l1->toString();
    l1->reverse();
    cout << l1->toString();
    delete l1, l1 = nullptr;

    return 0;
}