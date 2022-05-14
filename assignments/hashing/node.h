#pragma once
#ifndef NODE_H
#define NODE_H

#include "person.h"

class Node{
    private:
        Person* human;
        Node *next;
    public:
        Node() : human(nullptr), next(nullptr) {};
        Node(Person* p) : human(p), next(nullptr) {};
        void setNext(Node *n);
        Person* getData() const;
        Node *getNext() const;
};

#endif