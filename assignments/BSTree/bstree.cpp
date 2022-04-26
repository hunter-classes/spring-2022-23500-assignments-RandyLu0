#include "bstree.h"

using std::to_string;

BSTree::BSTree() { root = nullptr; }

string BSTree::get_debug_string(Node *root){
    if (root == nullptr) return "";
    return to_string(root->getData()) + " " +
    get_debug_string(root->getLeft()) + " " +
    get_debug_string(root->getRight());
}

string BSTree::wrap(){ return get_debug_string(root); }

void BSTree::setup(){
    Node *n = new Node(10);
    root = n;
    n = new Node(20);
    root->setRight(n);
    Node *n2 = new Node(30);
    n->setRight(n2);
    n2 = new Node(15);
    n->setLeft(n2);
    n2 = new Node(5);
    root->setLeft(n2);
    n = new Node(3);
    n2->setLeft(n);
    n = new Node(7);
    n2->setLeft(n);
}