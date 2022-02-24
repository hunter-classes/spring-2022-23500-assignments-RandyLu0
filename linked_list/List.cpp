#include "List.h"

List::List(){ head = nullptr; }

List::~List(){
    Node *p = head;
    while(p){
        Node *d = p;
        p = p->getNext();
        delete d, d = nullptr;
    }   
} 

void List::insert(int i, string s){
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

void List::sort(int a, int b){
    //sort
    if(a == b) return;
    int k = floor(a + b) / 2;
    sort(a,k);
    sort(k+1,b);
    
    //merge
    Node *i = locate(a);
    Node *left = locate(a);
    Node *right = locate(k + 1); 
    Node *end = locate(b);
    while(i != end){
        auto t = i->getData();
        auto l = left->getData();
        auto r = right->getData();
        if(t > l and r >= l){
            i->setData(l);
            left->setData(t);
            left = left->getNext();
        }else if (t > r and l > r){
            i->setData(r);
            right->setData(t);
            if(i == left) left = right;
            if(right != end) right = right->getNext();
        }else left = left->getNext();
        i = i->getNext();
    }
}