#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}

int DoublyLinkedList::getSize() const {
    return size;
}

void DoublyLinkedList::pushFront(Antenna val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoublyLinkedList::pushBack(Antenna val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::insertAfter(int index, Antenna val) {
    if (index < 0 || index >= size) {
        cout << "Error: Index out of bounds." << endl;
        return;
    }
    
    if (index == size - 1) {
        pushBack(val);
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    Node* newNode = new Node(val);
    Node* nextNode = current->next;

    current->next = newNode;
    newNode->prev = current;
    newNode->next = nextNode;
    if (nextNode != nullptr) {
        nextNode->prev = newNode;
    }

    size++;
}

void DoublyLinkedList::popFront() {
    if (isEmpty()) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

void DoublyLinkedList::popBack() {
    if (isEmpty()) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

void DoublyLinkedList::removeByValue(Antenna val) {
    if (isEmpty()) return;

    Node* current = head;
    while (current != nullptr) {
        if (current->data == val) {
        
            if (current == head) {
                popFront();
                return; 
            }
        
            else if (current == tail) {
                popBack();
                return;
            }

            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                size--;
                return;
            }
        }
        current = current->next;
    }
    cout << "Element not found." << endl;
}

void DoublyLinkedList::displayForward() const {
    if (isEmpty()) {
        cout << "List is empty." << endl;
        return;
    }
    Node* current = head;
    cout << "Forward List: " << endl;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

void DoublyLinkedList::displayBackward() const {
    if (isEmpty()) {
        cout << "List is empty." << endl;
        return;
    }
    Node* current = tail;
    cout << "Backward List: " << endl;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->prev;
    }
    cout << "nullptr" << endl;
}