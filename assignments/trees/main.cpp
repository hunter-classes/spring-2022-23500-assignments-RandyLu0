#include "node.h"
#include "bstree.h"
#include <iostream>

using std::cout;

int main(){

    BSTree *t = new BSTree();
    bool f = t->root == nullptr;
    cout << f << "\n";

    t->insert(0);

    delete t, t = nullptr;
    return 0;
}