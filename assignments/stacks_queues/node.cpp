#include "node.h"

Node::Node(){ setNext(nullptr); }

Node::Node(int d){ setData(d); setNext(nullptr); }

Node::Node(int d, Node *n){ setData(d); setNext(n); }

void Node::setData(int d){ data = d; }

void Node::setNext(Node *n){ next = n; }

int Node::getData() const{ return data; }

Node *Node::getNext() const{ return next; } 

