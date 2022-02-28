//
// Created by Sebastian Kaeser on 24.08.21.
//

#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H
#include <iostream>



template<typename T>
struct Node
{
    Node* next;
    T data;
    Node(T val,Node* next){
        this->next = next;
        this->data = val;
    }
    Node(T val){
        this->data = val;
        this->next = nullptr;
    }
};



template<typename T>
class LinkedList_ {
public:
    LinkedList_(){
        this->clear();
        std::cout << "[STATUS] " << "List created!" << std::endl;
    }
    void clear(){
        this->size = 0;
        this->head = nullptr;
    }
    int get_size(){
        return this->size;
    }
    bool isEmpty(){
        return this->size == 0;
    }
    void add(T value){
        if(head == nullptr){
            head = new Node<T>(value, nullptr);
            size++;
            return;
        }
        Node<T> *p = head;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = new Node<T>(value,nullptr);
        size++;

    }
    T set(int idx, T value){
        int old;
        if(idx > size || idx < 0){
            std::cout << "Index out of Bounds" << std::endl;
            return -1;
        }
        if(head == nullptr){
            std::cout << "List is empty" << std::endl;
            return -2;
        }
        Node<T> *p = head;
        for(int i=0; i < idx; i++){
            p = p->next;
        }
        old = p->data;
        p->data = value;
        return old;
    }
    T* get(int idx){
        /*if(idx < 0 || idx > size){
            std::cout << "Index out of Bounds" << std::endl;
            return nullptr;
        }*/
        Node<T> *p = head;
        for(int i=0; i < idx;i++){
           p = p->next;
        }
        return &p->data;
    }
    int remove_idx(int idx){
        if(idx > size || idx < 0){
            std::cout << "Index out of Bounds" << std::endl;
            return -3;
        }
        if(this->size == 0){
           return -2;
        }
        if(this->size == 1){
            clear();
            return -1;
        }
        if(idx == 0){
            auto *p = head;
            head = head->next;
            delete p;
            size--;
            return 1;
        }
        Node<T> *p = head;
        for(int i=0; i < idx; i++){
            p = p->next;
        }
        Node<T> *tmp = p->next;
        p->next = p->next->next;
        T old = tmp->data;
        delete tmp;
        size--;
        return 0;
    }
     bool remove(T value){
        if(head == nullptr){
            return false;
        }
        Node<T> *p = head;
        while(p != nullptr){
            if(p->next->data == value){
                Node<T> *tmp = p->next;
                p->next = p->next->next;
                delete tmp;
                return true;
            }
            p = p->next;
        }
        return false;

    }
    friend std::ostream& operator<<(std::ostream& os,LinkedList_& ll){
        os << "{ ";
        Node<T> *p = ll.head;
        while (p != nullptr)
        {
            os << p->data << ", ";
            p = p->next;
        }
        os << "}, size=" << ll.size;
        return os;
    }
    friend std::istream& operator>>(std::istream& is,LinkedList_& ll){
        T x;
        is >> x;

        ll.add(x);
        return is;
    }
private:
    Node<T>* head;
    int size;
};

std::istream& operator<<(std::istream&,int&);






#endif //ALGORITHMS_LINKEDLIST_H
