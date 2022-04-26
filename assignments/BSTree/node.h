#pragma once
#ifndef NODE_H
#define NODE_H

class Node{
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node();
        Node(int d, Node* l, Node* r);
        Node(int d);
        

};

#endif