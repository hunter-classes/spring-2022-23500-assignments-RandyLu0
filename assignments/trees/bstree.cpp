#include "bstree.h"
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

BSTree::BSTree() { root = nullptr; }

void BSTree::clear(Node* root){
    if(root == nullptr) return;
    clear(root->getLeft());
    clear(root->getRight());
    delete root, root = nullptr;
}

BSTree::~BSTree(){ clear(root); }

int BSTree::rsearch(int key, Node* root){
    if(root == nullptr) throw std::out_of_range("key not found");
    if(root->getData() == key) return key;
    if(root->getData() > key) return rsearch(key, root->getLeft());
    return rsearch(key, root->getRight());
}

int BSTree::rsearch(int key){ return rsearch(key, root); }

void BSTree::insert(int key, Node* current){
    if(root == nullptr){  
        this->root = new Node(key);
        return;
    }
    if(root->getData() > key){
        if(root->getLeft() == nullptr){
            Node *v = new Node(key);
            root->setLeft(v);
            return;
        }else insert(key, root->getLeft());
    }
    if(root->getData() < key){
        if(root->getRight() == nullptr){
            Node *v = new Node(key);
            root->setRight(v);
            return;
        }else insert(key, root->getRight());
    }
    if(root->getData() == key) throw std::out_of_range("key already in tree");

}

void BSTree::insert(int key){ insert(key, root); }

void BSTree::setup(){
    Node *a = new Node(10);
    Node *b = new Node(5);
    Node *c = new Node(7);
    Node *d = new Node(3);
    Node *e = new Node(20);
    Node *f = new Node(15);
    Node *g = new Node(30);
    a->setLeft(b);
    b->setLeft(d);
    b->setRight(c);
    a->setRight(e);
    e->setLeft(f);
    e->setRight(g);
    root = a;
}