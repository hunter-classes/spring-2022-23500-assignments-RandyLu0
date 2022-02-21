#include "List.h"

List::List(){ head = nullptr, size = 0; }

List::~List(){
    int s = size;
    while(s--) remove(s); 
} 

void List::insert(int i, string s){
    ++size;
    Node *node = new Node(s);
    Node *p = head;
    if(i == 0){
        node->setNext(head), head = node;
        return;
    }
    while(--i) p = p->getNext();
    node->setNext(p->getNext());
    p->setNext(node);
}

void List::remove(int i){
    --size;
    Node *p = head;
    if(i == 0){
        head = p->getNext();
        delete p, p = nullptr;
        return;    
    }
    while(--i) p = p->getNext();
    Node *d = p->getNext();
    p->setNext(d->getNext());
    delete d, d = nullptr;
}

Node* List::locate(int i) const{
    Node *p = head;
    while(i--) p = p->getNext();
    return p;
}

void List::reverse(Node* previous, Node *current){
    if(current == nullptr){
        head = previous;
        return;
    }
    reverse(current,current->getNext());
    current->setNext(previous);
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