#pragma once
#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List{
    private:
        Node *head;
        int size;
    public:
        List();
        ~List();
        void insert(int i, string s);
        void remove(int i); 
        Node* locate(int i) const;
        void reverse(Node *previous, Node *current);
        string toString() const;
};

#endif 