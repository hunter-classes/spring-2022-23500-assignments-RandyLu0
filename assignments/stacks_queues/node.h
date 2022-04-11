#pragma once
#ifndef NODE_H
#define NODE_H

class Node{
    private:
        int data;
        Node *next;
    public:
        Node();
        Node(int d);
        Node(int d, Node *n);
        void setData(int d);
        void setNext(Node *n);
        int getData() const;
        Node *getNext() const;
};

#endif