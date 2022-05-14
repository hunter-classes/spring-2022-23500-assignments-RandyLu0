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

void List::remove(int index){
    if (head == nullptr) throw out_of_range("Empty list\n");
    Node *p = head, *t = nullptr;
    if(index <= 0) head = p->getNext();
    else{
        while(index-- > 0 and p->getNext() != nullptr)
            t = p, p = p->getNext();
        t->setNext(p->getNext());
    }
    delete p, p = nullptr;
}

void List::insert(Person* a){
    Node *node = new Node(a);
    node->setNext(head), head = node;
}

Person* List::find(string key) const{
    Node *p = head;
    while(p != nullptr and p->getData()->get_name() != key){
        p = p->getNext();
    }
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

