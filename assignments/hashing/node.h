#pragma once
#ifndef NODE_H
#define NODE_H

#include "person.h"

class Node{
    private:
        Person human;
        Node *next;
    public:
        Node();
        Node(Person p);
        void setData(Person p);
        void setNext(Node *n);
        Person getData() const;
        Node *getNext() const;
};

#endif