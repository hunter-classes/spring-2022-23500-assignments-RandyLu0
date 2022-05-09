#pragma once
#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include <string>
using std::string;

class BSTree{
private:
    Node* root;
    int rsearch(int key, Node* root) const;
    void insert(int key, Node* root);
    void clear(Node* root);
    int height(Node* root) const;
public:
    BSTree() : root(nullptr) {};
    ~BSTree();
    int rsearch(int key) const;
    void insert(int key);
    void remove(int key);
    int height() const;
};

#endif