#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person{
private:
    string name; 
    int id;
public:
    Person(string name, int id) : name(name), id(id) {};
    string get_name() const;
    int get_id() const;
};

#endif