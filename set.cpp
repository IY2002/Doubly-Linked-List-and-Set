//
// Created by som3a on 4/9/2022.
//

#include "set.h"
#include <iostream>

using namespace std;

Set::Set() {

    list = new List();
    set_size = 0;

}

Set::~Set() {
    clear();
    delete list;
    list = nullptr;
}

bool Set::contains(int value) {
    return list->contains(value);
}

bool Set::add(int value) {
    if(list->contains(value)){
        return false;
    }
    list->addToTail(value);
    set_size++;
    return true;
}

bool Set::remove(int value) {
    if(list->contains(value)){
        set_size--;
        return list->remove(value);
    }
    return false;
}

void Set::clear() {
    while (!list->isEmpty())
        list->removeTail();
    set_size = 0;
}

Set *Set::set_union(Set &subject) {
    Set* result = new Set;
    for(int i = 0 ; i < set_size;i++){
        result->add(this->list->at(i));
    }
    for(int j = 0; j < subject.size(); j++){
        result->add(subject.list->at(j));
    }
    return result;
}

Set *Set::intersection(Set &subject) {
    Set* result = new Set;
    for(int i =0; i < set_size; i++){
        if(subject.contains(this->list->at(i))){
            result->add(this->list->at(i));
        }
    }
    return result;
}

Set *Set::difference(Set &subject) {
    Set* result = new Set;
    for(int i =0; i < set_size; i++){
        if(!subject.contains(this->list->at(i))){
            result->add(this->list->at(i));
        }
    }

    return result;
}

void Set::print() {
    for(int i =0; i < set_size; i ++){
        cout << list->at(i) << " ";
    }
    cout << endl;
}
