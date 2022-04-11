#include "list.h"
#include "node.h"

List::List(){ head = nullptr; }

List::~List(){
    while(head){
        Node *d = head;
        head = head->getNext();
        delete d, d = nullptr;
    }   
}

void List::remove(int loc){
    Node *p = head, *t = nullptr;
    if (head == nullptr) throw std::out_of_range("Empty list\n");
    if(loc <= 0) head = p->getNext();
    else{ 
        while(loc-- > 0 and p->getNext())
            t = p, p = p->getNext();
        t->setNext(p->getNext());
    }
    delete p, p = nullptr;
}

void List::insert(int i, int d){
    Node *node = new Node(d), *p = head;
    if(i == 0){
        node->setNext(head), head = node; return;
    }
    while(--i) p = p->getNext();
    node->setNext(p->getNext());
    p->setNext(node);
}

int List::get(int i) const{
    Node *p = head;
    if (head == nullptr) throw std::out_of_range("Empty list\n");
    while(i-- >  0 and p->getNext()) p = p->getNext();
    return p->getData();
}

