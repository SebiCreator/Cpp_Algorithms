//
// Created by Sebastian Kaeser on 24.08.21.
//

#include "LinkedList.h"
#include <iostream>

void LinkedList::addNode(int val) {
    if(head == nullptr)
    {
        head = new Node(nullptr,val);
    }
    else {
        Node* p = head;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = new Node(nullptr,val);
    }
}


LinkedList::Node::Node(Node* Next, int Val) {
    this->next = Next;
    this->value = Val;
}

void LinkedList::traverse() {
    for(Node* p = head; p=p->next; p != nullptr)
    {
       std::cout << p->value << std::endl;
    }
}