#pragma once
#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <stdexcept>

class List{
    private:
        Node *head;
    public:
        List();
        ~List();
        int get(int i) const;
        void insert(int i, int d);
        void remove(int i); 
        std::string toString() const;
};

#endif 