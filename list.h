//
// Created by som3a on 4/9/2022.
//

#ifndef HW4_LIST_H
#define HW4_LIST_H


#include <cstdlib>

class ListNode
{
private:
    int data;
    ListNode* prev;
    ListNode* next;

public:
    ListNode() { prev = next = nullptr; data = NULL;}
    ListNode(int d, ListNode* p, ListNode* n) { data = d; prev = p; next = n; }

    friend class List;
};

class List
{
private:
    ListNode* head;
    ListNode* tail;
    int numNodes;

public:
    List() { head = tail = nullptr; numNodes = 0; }
    ~List();

    bool isEmpty() { return head == nullptr; }
    bool contains(int );

    void addToHead(int );
    void addToTail(int );

    int removeHead();
    int removeTail();

    int removeAt(int );
    bool remove(int);

    int at(int );
    static int valueOf(const ListNode* );
    static const ListNode* getNext(const ListNode* );
    static const ListNode* getPrevious(const ListNode* );
    const ListNode* getHead() { return head; }
    const ListNode* getTail() { return tail; }
};



#endif //HW4_LIST_H
