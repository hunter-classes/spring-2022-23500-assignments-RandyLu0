#include "node.h"
#include "bstree.h"
#include <iostream>

using std::cout;

int main(){

    BSTree *t = new BSTree();

    t->insert(0,t->root);

    delete t, t = nullptr;
    return 0;
}