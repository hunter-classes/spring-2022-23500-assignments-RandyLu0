#pragma once
#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include <string>
using std::string;

class BSTree{
private:
    Node *root;
public:
    BSTree();
    string get_debug_string(Node *root);
    string wrap();
    void setup();
};

#endif