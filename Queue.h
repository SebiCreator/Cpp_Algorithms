//
// Created by Sebastian Kaeser on 03.01.22.
//

#ifndef CPP_ALGORITHMS_QUEUE_H
#define CPP_ALGORITHMS_QUEUE_H

#include "LinkedList.h"

template<typename T>
class Queue_ {
public:
    Queue_(){
        this->clear();
    }
    void clear(){
        this->size = 0;
        this->rear = nullptr;
        this->front = nullptr;
    }
    void insert(T value){
       Node<T> *tmp = new Node<T>(value);
       if(rear == nullptr){
           front = rear = tmp;
           return;
       }
       rear->next = tmp;
       rear = tmp;
    }
    T remove(){
        if(front == nullptr){
            return nullptr;
        }
        Node<T> *tmp = front;
        T val = front->data;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete tmp;
        return val;
    }
    T peek(){
        if(front == nullptr){
            return nullptr;
        }
        return front->data;
    }
    int get_size(){
        return this->size;
    }
private:
    Node<T> *front;
    Node<T> *rear;
    int size;
};


#endif //CPP_ALGORITHMS_QUEUE_H
