#ifndef LIST_H
#define LIST_H

#include <memory>
#include <iostream>
#include "Antenna.h"

using namespace std;

class ListNode {
public:
    shared_ptr<Antenna> data;
    
    shared_ptr<ListNode> next;
    
    weak_ptr<ListNode> prev;

    ListNode(shared_ptr<Antenna> val) : data(val) {
        cout << "  [List] Node created." << endl;
    }
    
    ~ListNode() {
        cout << "  [List] Node destroyed." << endl;
    }
};

#endif