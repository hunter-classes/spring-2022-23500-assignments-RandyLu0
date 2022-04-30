#include "bstree.h"
#include <iostream>

using std::cout;

int main(){
    BSTree *t = new BSTree();

    for(int i = 0; i < 7; i++) t->insert(i);

    try{
        t->insert(5);
        for(int i = 0; i < 7; i++) cout << t->rsearch(i) << "\n";
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    delete t, t = nullptr;
    
    return 0;
}