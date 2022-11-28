//
// Created by som3a on 4/9/2022.
//

#ifndef HW4_SET_H
#define HW4_SET_H

#include <iostream>
#include "list.h"

using namespace std;

class Set
{
private:
    List* list;
    int set_size;
public:
    Set();
    ~Set();

    bool contains(int value);
    bool add(int value);
    bool remove(int value);
    void clear();

    Set* set_union(Set&);
    Set* intersection(Set&);
    Set* difference(Set&);

    void print();
    int size() const { return set_size; }
};



#endif //HW4_SET_H
