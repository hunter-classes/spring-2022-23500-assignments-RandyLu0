#pragma once
#ifndef MAP_H

#include "person.h"

class Dictionary{
private:
    ~Dictionary();
public:
    Dictionary();
    void insert(Person *p);
    Person* find(string key) const;
    string keys() const;
};

#endif