#include "List.h"

List::List(){
    head = nullptr;
    size = 0;
}

List::~List(){
    int s = size;
    while(s-- >= 1) remove(s); 
} 

void List::insert(int i, string s){
    ++size;
    Node *node = new Node(s);
    Node *p = head;
    if(i == 0){
        node->setNext(head);
        head = node;
        return;
    }
    while(i-- > 1) p = p->getNext();
    //middle
    if(i + 1 != size) node->setNext(p->getNext());
    p->setNext(node);
}

void List::remove(int i){
    --size;
    Node *p = head;
    if(i == 0){
        head = p->getNext();
        delete p;
        return;    
    }
    while(i-- > 1) p = p->getNext();
    Node *d = p->getNext();
    //middle
    if(i + 1 != size) p->setNext(d->getNext());
    delete d;
    d = nullptr;
}

string List::toString() const{
    Node *p = head;
    string s = "";
    while(p){
        s += p->getData() + "-->";
        p = p->getNext(); 
    }
    return s + "nullptr\n";
}