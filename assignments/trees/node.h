#pragma once
#ifndef NODE_H
#define NODE_H

class Node{
private:
    int data;
    Node* left;
    Node* right;
public:
    Node(int key) : data(key), left(nullptr), right(nullptr) {};
    int getData() const;
    void setData(int key);
    Node* getLeft() const;
    Node* getRight() const;
    void setLeft(Node *l);
    void setRight(Node *r);
};

#endif