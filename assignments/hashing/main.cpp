#include "map.h"
#include <iostream>
using std::cout;


int main(){
    Dictionary *d = new Dictionary();
    Person *p = new Person("Randy", "Lu",0);
    Person *p1 = new Person("Randy", "Lu",3);
    Person *p2 = new Person("Randy", "Li",2);
    Person *p3 = new Person("Randy", "Ly",1);
    d->insert(p);
    d->insert(p1);
    d->insert(p2);
    d->insert(p3);
    cout << d->keys();
    delete d, d = nullptr;
    delete p;
    delete p1;
    delete p2;
    delete p3;
    return 0;
}