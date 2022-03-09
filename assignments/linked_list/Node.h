#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>
using std::string;

class Node{
    private:
        string data;
        Node *next;
    public:
        Node();
        Node(string d);
        Node(string d, Node *n);
        void setData(string d);
        void setNext(Node *n);
        string getData() const;
        Node *getNext() const;
};

#endif