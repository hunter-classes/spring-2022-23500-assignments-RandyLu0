#include "node.h"

Node::Node(int data){
    this->data = data;
    left = nullptr, right = nullptr;
}

int Node::getData(){ return data; }

Node *Node::getLeft(){ return left; }

Node *Node::getRight(){ return right; }

void Node::setLeft(Node *l){ left = l; }

void Node::setRight(Node *r){ right = r; }