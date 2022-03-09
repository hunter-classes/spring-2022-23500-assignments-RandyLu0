#pragma once
#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <stdexcept>

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
};

class OList{
    private:
        Node *head;
    public:
        OList();
        ~OList();
        void insert(string value);
        void remove(int loc); 
        string get(int loc) const;
        void reverse();
        void r(Node *p, Node *c);
        string toString() const;
        bool contains(string value) const;
};

#endif 