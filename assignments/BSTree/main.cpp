#include "node.h"
#include "bstree.h"
#include <iostream>

using std::cout;

int main(){
    /*
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *d = new Node(30);
    Node *c = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(60);
    Node *g = new Node(70);
    a->setLeft(b);
    b->setLeft(d);
    d->setLeft(c);
    a->setRight(e);
    e->setLeft(f);
    e->setRight(g);
    delete a;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete b;
    */

    BSTree *t = new BSTree();
    t->setup();
    cout << t->wrap();

    return 0;
}