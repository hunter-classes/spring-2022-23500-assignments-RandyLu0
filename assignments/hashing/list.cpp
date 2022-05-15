#include "list.h"
#include "node.h"

using std::out_of_range;

List::~List(){
    while(head){
        Node *d = head;
        head = head->getNext();
        delete d, d = nullptr;
    }   
}

void List::insert(Person* a){
    Node *node = new Node(a);
    node->setNext(head), head = node;
}

Person* List::find(string key) const{
    Node *p = head;
    while(p and p->getData()->get_name() != key) p = p->getNext();
    return p->getData();
}

string List::names() const{
    Node *p = head;
    string data = "";
    while(p != nullptr){
        data += p->getData()->get_name() + "\n";
        p = p->getNext();
    }
    return data;
}

