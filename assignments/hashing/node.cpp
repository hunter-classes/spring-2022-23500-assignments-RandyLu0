
#include "node.h"

void Node::setNext(Node *n){ next = n; }

Person* Node::getData() const{ return human; }

Node *Node::getNext() const{ return next; } 