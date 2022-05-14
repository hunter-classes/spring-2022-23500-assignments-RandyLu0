#pragma once
#ifndef SET_H

#include "person.h"
#include "list.h"

#define SIZE 11

class Dictionary{
private:
    List* table[SIZE];
    int hash(string key) const;
public:
    ~Dictionary();
    Dictionary();
    void insert(Person* p);
    Person* find(string key) const;
    string keys() const;
};

#endif