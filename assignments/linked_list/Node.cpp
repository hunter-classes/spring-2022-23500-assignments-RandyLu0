#include "Node.h"

Node::Node(){ setNext(nullptr); }

Node::Node(string d){ 
    setData(d); 
    setNext(nullptr);
}

Node::Node(string d, Node *n){
    setData(d);
    setNext(n);
}

Node::~Node(){ 
    delete this;

}

void Node::setData(string d){ data = d; }

void Node::setNext(Node *n){ next = n; }

string Node::getData() const{ return data; }

Node *Node::getNext() const{ return next; } 

