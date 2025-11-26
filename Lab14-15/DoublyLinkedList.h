#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Antenna.h"

struct Node {
    Antenna data;
    Node* next;
    Node* prev;

    Node(Antenna val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool isEmpty() const;
    int getSize() const;

    void pushFront(Antenna val);
    void pushBack(Antenna val);
    void insertAfter(int index, Antenna val);

    void popFront();
    void popBack();
    void removeByValue(Antenna val);

    void displayForward() const;
    void displayBackward() const;
    
    void clear();
};

#endif