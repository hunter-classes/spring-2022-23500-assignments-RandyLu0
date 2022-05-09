#include "bstree.h"
#include <stdexcept>

#define MAX(A,B) A > B ? A : B

BSTree::~BSTree(){ clear(root); }

void BSTree::clear(Node* root){
    if(root == nullptr) return;
    clear(root->getLeft()); clear(root->getRight());
    delete root, root = nullptr;
}

int BSTree::rsearch(int key) const { return rsearch(key, root); }

int BSTree::rsearch(int key, Node* root) const{
    if(root == nullptr) throw std::out_of_range("key not found");
    if(root->getData() == key) return key;
    if(root->getData() > key) return rsearch(key, root->getLeft());
/*  if(root->getData() < key)*/return rsearch(key, root->getRight());
}

void BSTree::insert(int key){ insert(key, root); }

void BSTree::insert(int key, Node* root){
    if(root == nullptr){ this->root = new Node(key); return; }
    if(root->getData() > key){
        if(root->getLeft() == nullptr) root->setLeft(new Node(key));
        else insert(key, root->getLeft());
    }else if(root->getData() < key){
        if(root->getRight() == nullptr) root->setRight(new Node(key));
        else insert(key, root->getRight());
    }
}

void BSTree::remove(int key){
    Node *previous = nullptr, *current = root;
    //moves to correct verticies 
    while(current != nullptr and current->getData() != key){
        previous = current;
        if(current->getData() > key) current = current->getLeft();
        else if(current->getData() < key) current = current->getRight();
    } if(current == nullptr) throw std::out_of_range("key not found");
    //removal
    int c = current->getData();
    Node *l = current->getLeft(), *r = current->getRight();
    //0 children 
    if(l == nullptr and r == nullptr){
        if(current == root) delete root, root = nullptr;
        else{ 
            if(c > previous->getData()) previous->setRight(nullptr);
            else if(c < previous->getData()) previous->setLeft(nullptr);
            delete current, current = nullptr; 
        } return;
    }
    //1 child
    if(l == nullptr or r == nullptr){
        if(current == root) root = l == nullptr ? r : l;
        else{ Node* next = l == nullptr ? r : l; 
            if(c > previous->getData()) previous->setRight(next);
            else if(c < previous->getData()) previous->setLeft(next); 
        } delete current, current = nullptr; return;
    }
    //2 children by in order successor
    Node *successor = r;
    while(successor->getLeft() != nullptr) successor = successor->getLeft();
    int temp = successor->getData();
    remove(temp); current->setData(temp);
}

int BSTree::height() const{ return height(root); }

int BSTree::height(Node* root) const{
    if(root == nullptr) return 0;
    return MAX(1 + height(root->getLeft()), 1 + height(root->getRight()));
}