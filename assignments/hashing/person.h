#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person{
    private:
        string first; // first name
        string last; // last name
        int idnum; // some id number
    public:
        Person(string f, string l, int n) 
            : first(f), last(l), idnum(n) {};
        string get_name() const;
        int get_id() const;
};
#endif