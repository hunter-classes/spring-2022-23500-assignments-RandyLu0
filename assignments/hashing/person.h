#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person{
    private:
        string name; 
    public:
        Person(string name, int n) : name(name) {};
        string get_name() const;
};

#endif