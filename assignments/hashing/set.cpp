#include "set.h"

Dictionary::Dictionary(){
    for(int i = 0; i < SIZE; i++) table[i] = new List(); 
}

Dictionary::~Dictionary(){
    for(int i = 0; i < SIZE; i++) delete table[i], table[i] = nullptr;
}

int Dictionary::hash(string key) const{
    int value = 0;
    for(auto letter : key) value += int(letter);
    return value % SIZE;
}

void Dictionary::insert(Person* a){ table[hash(a->get_name())]->insert(a); }

string Dictionary::keys() const{
    string list = "";
    for(int i = 0; i < SIZE; i++) if(table[i]) list += table[i]->names();
    return list;
}

Person* Dictionary::find(string key) const{
    int value = hash(key);
    if(table[value] == nullptr) return nullptr;
    return table[value]->find(key); 
}