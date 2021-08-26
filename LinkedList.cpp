//
// Created by Sebastian Kaeser on 24.08.21.
//

#include "LinkedList.h"
#include <iostream>


LinkedList_::LinkedList_() {
    this->clear();
    std::cout << "[STATUS] " << "List created!" << std::endl;
}

void LinkedList_::clear() {
   this->size = 0;
   head = nullptr;
}

int LinkedList_::get_size() {
    return this->size;
}

bool LinkedList_::isEmpty() {
    return this->size== 0;
}

void LinkedList_::add(int x) {
    if (head == nullptr) {
        head = new Node(x, nullptr);
    } else
    {
        Node* p = head;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = new Node(x, nullptr);
        size ++;
    }
}

int LinkedList_::set(int val, int idx)
{
    int old;
    if(idx < 0 || idx > size)
    {
        std::cout << "Index out of Bounds" << std::endl;
        return 0;
    }
    if(head == nullptr)
    {
        std::cout << "List ist leer" << std::endl;
        return 0;
    }
    Node* p = head;
    for(int i=0; i < idx; i++)
    {
       p = p->next;
    }
    old = p->data;
    p->data = val;

    return old;
}

int LinkedList_::get(int idx) {
    if(idx < 0 || idx > this->size)
    {
        std::cout << "Index out of Bounds!" << std::endl;
        return 0;
    }
    Node* p=head;
    for(int i=0; i < idx; i++)
    {
        p = p->next;
    }
    return p->data;
}

void LinkedList_::remove(int value) {
   Node* p = head;
   while(p != nullptr)
   {
       if(p->next->data == value)
       {
          p->next = p->next->next;
          break;
       }
       p = p->next;
   }
   size --;
}

std::ostream& operator<<(std::ostream& os, LinkedList_& ll) {
    os << "{ ";
    Node *p = ll.head;
    while (p != nullptr)
    {
        os << p->data << ", ";
        p = p->next;
    }
    os << "}, size=" << ll.size;
    return os;
}


std::istream& operator>>(std::istream& is, LinkedList_& ll)
{
    int x;
    is >> x;

    ll.add(x);
    return is;
}











Node::Node(int x, Node * p) {
    this->data = x;
    next = p;
}