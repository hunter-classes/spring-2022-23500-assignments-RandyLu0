#pragma once
#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <cmath>

class List{
    private:
        Node *head;
    public:
        List();
        ~List();
        void insert(int i, string s);
        void remove(int i); 
        Node* locate(int i) const;
        void reverse(Node *previous, Node *current);
        string toString() const;
        void sort(int a, int b);
        void merge(int a, int b);
};

#endif 