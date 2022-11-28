//
// Created by som3a on 4/9/2022.
//

#include "list.h"

 // done

List::~List()
{
    while (!isEmpty())
        removeTail();
}

bool List::contains(int value)
{
    ListNode *temp = head;
    while (temp != nullptr && temp->data != value)
        temp = temp->next;

    return temp != nullptr;
}

void List::addToHead(int value)
{
    if (isEmpty())
    {
        head = tail = new ListNode(value, nullptr, nullptr);
    }
    else
    {
        head = new ListNode(value, nullptr, head);
        head->next->prev = head;
    }
    numNodes++;
}

void List::addToTail(int value)
{
    if (isEmpty())
    {
        head = tail = new ListNode(value, nullptr, nullptr);
    }
    else
    {
        tail = new ListNode(value, tail, nullptr);
        tail->prev->next = tail;
    }
    numNodes++;
}

int List::removeHead()
{
    int value = head->data;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    numNodes--;
    return value;
}

int List::removeTail()
{
    int value = tail->data;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    numNodes--;
    return value;
}

int List::removeAt(int index) {

    if(numNodes <= index){
        exit(1);
    } else if(index == 0){
        removeHead();

    }
    else if(index == numNodes -1){
        removeTail();

    }
    else{
        ListNode* temp = head;
        for (int i =0; i < index; i++){
            temp = temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        int value = temp->data;
        delete temp;
        numNodes--;
        return value;
    }

}

bool List::remove(int value)
{
    ListNode* temp = head;
    int index = 0;
    if(temp->data == value){
        removeHead();

        return true;
    }
    for(int i = 0; i < numNodes - 1; i++){
        temp = temp->next;
        if(temp->data == value){
            removeAt(i);
            return true;
        }
    }
    return false;
}

int List::at(int index)
{
    ListNode* temp = head;
    if(numNodes <= index){
        exit(1);
    } else{
        for (int i =0; i < index; i++){
            temp = temp->next;
        }
        int value = temp->data;
        return value;
    }
}

const ListNode* List::getNext(const ListNode* node)
{
    return node->next;
}

const ListNode* List::getPrevious(const ListNode* node)
{
    return node->prev;
}

int List::valueOf(const ListNode *elem) {
    return elem->data;
}
