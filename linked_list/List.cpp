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

OList::OList(){ head = nullptr; }

OList::~OList(){
    while(head){
        Node *d = head;
        head = head->getNext();
        delete d, d = nullptr;
    }   
}

string OList::toString() const{
    Node *p = head;
    string s = "";
    while(p){
        s += p->getData() + "-->";
        p = p->getNext(); 
    }
    return s + "nullptr\n";
}

void OList::insert(string value){
    Node *new_node = new Node(value);
    Node *p = head, *t = nullptr;
    if(head == nullptr) head = new_node;
    else while(p){
        if(p->getData() > new_node->getData()){
            new_node->setNext(p);
            if(p == head) head = new_node;
            else t->setNext(new_node);
            return;
        }
        t = p;
        p = p->getNext();
    }
}

void OList::r(Node* p, Node *c){
    if(c == nullptr){
        head = p;
        return;
    }
    r(c,c->getNext());
    c->setNext(p);
}

void OList::reverse(){ r(nullptr,head); }

bool OList::contains(string value) const{
    Node *p = head;
    while(p){
        if(p->getData() == value) return true;
        p = p->getNext();
    }
    return false;
}

string OList::get(int loc) const{
    Node *p = head;
    while(loc-- >  0 and p->getNext()) p = p->getNext();
    return p->getData();
}

void OList::remove(int loc){
    Node *p = head, *t = nullptr;
    while(loc-- > 0 and p->getNext()){
        t = p;
        p = p->getNext();
    }
    if(loc <= 0) head = p->getNext();
    else t->setNext(p->getNext());
    delete p, p = nullptr;
}
