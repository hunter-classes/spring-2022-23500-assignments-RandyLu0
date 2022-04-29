#pragma once
#ifndef NODE_H
#define NODE_H

class Node{
private:
    int data;
    Node *left;
    Node *right;
public:
    Node(int data);
    int getData();
    Node *getLeft();
    Node *getRight();
    void setLeft(Node *l);
    void setRight(Node *r);
};

#endif