#include <iostream>
#include <memory>
#include <vector>
#include "Antenna.h"
#include "List.h"

using namespace std;


class ChildB;

class ChildA {
public:
    shared_ptr<ChildB> ptrB;
    ~ChildA() { cout << "  [~ChildA] Destroyed" << endl; }
};

class ChildB {
public:
    weak_ptr<ChildA> ptrA; 
    ~ChildB() { cout << "  [~ChildB] Destroyed" << endl; }
};

void demoUniquePtr() {
    cout << "\n====2. Demo: std::unique_ptr ====" << endl;
    

    unique_ptr<Antenna> item1 = make_unique<Antenna>("Yagi", 12.5, "HF");
    item1->print();

    cout << "Moving ownership from item1 to item2..." << endl;
    unique_ptr<Antenna> item2 = std::move(item1);

    if (item1 == nullptr) {
        cout << "item1 is now nullptr (ownership lost)." << endl;
    }
    
    if (item2 != nullptr) {
        cout << "item2 now owns the object: ";
        item2->print();
    }
    
    cout << "Exiting demoUniquePtr scope..." << endl;
}

void demoSharedPtr() {
    cout << "\n=== 3. Demo: std::shared_ptr ===" << endl;

    shared_ptr<Antenna> ptr1 = make_shared<Antenna>("Dipole", 2.1, "VHF");
    cout << "Ptr1 created. Use count: " << ptr1.use_count() << endl;

    {
        shared_ptr<Antenna> ptr2 = ptr1;
        shared_ptr<Antenna> ptr3 = ptr1;
        cout << "Ptr2 and Ptr3 created (copies). Use count: " << ptr1.use_count() << endl;
        
        {
            shared_ptr<Antenna> ptr4 = ptr1;
            cout << "  Inside inner block (ptr4 created). Use count: " << ptr1.use_count() << endl;
        }
        cout << "  Left inner block. Use count: " << ptr1.use_count() << endl;
    }
    cout << "Left outer block. Use count: " << ptr1.use_count() << endl;
}

void demoWeakPtrCycle() {
    cout << "\n=== 4. Demo: std::weak_ptr (Cycle Prevention) ===" << endl;
    
    {
        auto a = make_shared<ChildA>();
        auto b = make_shared<ChildB>();

        a->ptrB = b;
        b->ptrA = a;

        cout << "a use_count: " << a.use_count() << endl;
        cout << "b use_count: " << b.use_count() << endl;
    }
    cout << "Exiting cycle scope. Destructors should be called above." << endl;
}

void demoLinkedList() {
    cout << "\n=== 5. Demo: Doubly Linked List with Smart Pointers ===" << endl;

    auto node1 = make_shared<ListNode>(make_shared<Antenna>("Dish", 30.0, "Ku-Band"));
    auto node2 = make_shared<ListNode>(make_shared<Antenna>("Patch", 5.0, "Wi-Fi"));
    auto node3 = make_shared<ListNode>(make_shared<Antenna>("Whip", 0.0, "FM"));

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    cout << "\nTraversing Forward:" << endl;
    shared_ptr<ListNode> current = node1;
    while (current) {
        current->data->print();
        current = current->next;
    }

    cout << "\nAccessing Previous from Node 2:" << endl;
    if (auto prevNode = node2->prev.lock()) {
        cout << "Predecessor of Patch is: ";
        prevNode->data->print();
    } else {
        cout << "No predecessor." << endl;
    }

    cout << "\nDestroying list head..." << endl;
}

int main() {
    demoUniquePtr();
    demoSharedPtr();
    demoWeakPtrCycle();
    demoLinkedList();

    cout << "\n=== End of Program ===" << endl;
    return 0;
}