#include "bstree.h"

BSTree::~BSTree(){ clear(root); }

void BSTree::clear(Node* root){
    if(root == nullptr) return;
    clear(root->getLeft()); clear(root->getRight());
    delete root, root = nullptr;
}

int BSTree::rsearch(int key) const { return rsearch(key, root); }

int BSTree::rsearch(int key, Node* root) const{
    if(root == nullptr) throw out_of_range("key not found");
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
    Node *previous = nullptr, *root = this->root;
    //moves to correct verticies 
    while(root != nullptr and root->getData() != key){
        previous = root;
        root = root->getData() > key ? root->getLeft() : root->getRight();
    } if(root == nullptr) throw out_of_range("key not found");
    //removal
    int c = root->getData();
    Node *l = root->getLeft(), *r = root->getRight();
    //0 children 
    if(l == nullptr and r == nullptr){
        if(root == this->root) delete this->root, this->root = nullptr;
        else{ 
            if(c > previous->getData()) previous->setRight(nullptr);
            else if(c < previous->getData()) previous->setLeft(nullptr);
            delete root, root = nullptr; 
        } return;
    }
    //1 child
    if(l == nullptr or r == nullptr){
        if(root == this->root) this->root = l == nullptr ? r : l;
        else{ Node* next = l == nullptr ? r : l; 
            if(c > previous->getData()) previous->setRight(next);
            else if(c < previous->getData()) previous->setLeft(next); 
        } delete root, root = nullptr; return;
    }
    //2 children by in order successor
    Node *s = r; while(s->getLeft() != nullptr) s = s->getLeft();
    int temp = s->getData(); remove(temp); root->setData(temp);
}

int BSTree::height() const{ return height(root); }

int BSTree::height(Node* root) const{
    if(root == nullptr) return 0;
    int lheight = root->getLeft() ? 1 + height(root->getLeft()) : 0, 
    rheight = root->getRight() ? 1 + height(root->getRight()) : 0;
    return MAX(lheight, rheight);
}

int BSTree::leaves() const{ return leaves(root); }

int BSTree::leaves(Node* root) const{
    if(root == nullptr) return 0;
    Node *l = root->getLeft(), *r = root->getRight();
    if(l == nullptr and r == nullptr) return 1;
    return leaves(l) + leaves(r);
}

int BSTree::levelsum(int depth) const{ 
    if(root == nullptr) throw out_of_range("empty tree");
    if(depth < 0 or height() < depth) throw out_of_range("invalid level");
    return levelsum(root, depth); 
}

int BSTree::levelsum(Node* root, int depth) const{
    if(depth == 0) return root->getData();
    int sum = 0;
    sum += root->getLeft() ? levelsum(root->getLeft(), depth - 1) : 0;
    sum += root->getRight() ? levelsum(root->getRight(), depth - 1) : 0;
    return sum;
}
