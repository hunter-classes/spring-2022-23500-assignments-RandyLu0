#include "bstree.h"
#include <iostream>

using std::cout;

int main(){

    BSTree *t = new BSTree();
    
    t->insert(10);
    t->insert(20);
    t->insert(30);
    t->insert(15);
    t->insert(5);
    t->insert(3);
    t->insert(6);
    cout << t->height() << "\n";
    cout << t->levelsum(2) << "\n";
    cout << t->leaves() << "\n";
    try{
        t->remove(10);
        t->remove(20);
        t->remove(30);
        t->remove(15);
        t->remove(5);
        t->remove(3);
        t->remove(6);
        cout << t->rsearch(30) << "\n";
        cout << t->height() << "\n";
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    delete t, t = nullptr;


    return 0;
}