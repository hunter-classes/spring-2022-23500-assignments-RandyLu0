#include "node.h"

int Node::getData() const{ return data; }

void Node::setData(int key){ data = key;}

Node* Node::getLeft() const{ return left; }

Node* Node::getRight() const{ return right; }

void Node::setLeft(Node *l){ left = l; }

void Node::setRight(Node *r){ right = r; }