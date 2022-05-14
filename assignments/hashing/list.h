#pragma once
#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <stdexcept>

class List{
    private:
        Node *head;
    public:
        ~List();
        List() : head(nullptr) {};
        Person* find(string key) const;
        void insert(Person* a);
        void remove(int index); 
        string names() const;
};

#endif 