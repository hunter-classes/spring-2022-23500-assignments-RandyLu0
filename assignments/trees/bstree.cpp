#include "bstree.h"
#include <stdexcept>

BSTree::BSTree() { root = nullptr; }

BSTree::~BSTree(){ clear(root); }

void BSTree::clear(Node* root){
    if(root == nullptr) return;
    clear(root->getLeft());
    clear(root->getRight());
    delete root, root = nullptr;
}

int BSTree::rsearch(int key){ return rsearch(key, root); }

int BSTree::rsearch(int key, Node* root){
    if(root == nullptr) throw std::out_of_range("key not found");
    if(root->getData() == key) return key;
    if(root->getData() > key) return rsearch(key, root->getLeft());
/*  if(root->getData() < key)*/return rsearch(key, root->getRight());
}

void BSTree::insert(int key){ insert(key, root); }

void BSTree::insert(int key, Node* root){
    if(root == nullptr){ 
        this->root = new Node(key); return;
    }
    if(root->getData() > key){
        if(root->getLeft() == nullptr) root->setLeft(new Node(key));
        else insert(key, root->getLeft());
    }   
    if(root->getData() < key){
        if(root->getRight() == nullptr) root->setRight(new Node(key));
        else insert(key, root->getRight());
    }
}
