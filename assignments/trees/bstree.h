#pragma once
#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include <string>
using std::string;

class BSTree{
private:
    Node *root;
    int rsearch(int key, Node* root);
    void insert(int key, Node* root);
    void clear(Node*);
public:
    BSTree();
    ~BSTree();
    int rsearch(int key);
    void insert(int key);
};

#endif