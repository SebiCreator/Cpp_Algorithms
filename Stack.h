//
// Created by Sebastian Kaeser on 26.08.21.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H

#include <iostream>
#define DEF_CAP 16

template<typename T>
class Stack_ {
public:
    Stack_(){
        this->clear();
    }
    void clear(){
        this->size = 0;
        this->data = new T[DEF_CAP];
        this->current_size = DEF_CAP;
    }
    int get_size(){
        return this->size;
    }
    bool isEmpty(){
        return this->size == 0;
    }
    void push(T value){
        data[size++] = value;
    }
    T peek(){
        return data[size-1];
    }
    T pop(){
        if(this->isEmpty()){
            std::cout << "Stack is leer" << std::endl;
        }
        int value = data[size--];
        return value;
    }
    void swap(T val1,T val2){
        assert(val1 != val2);
        int idx1,idx2;
        bool found1 = false, found2 = false;
        for(int i=0; i < size;i++){
            if(data[i] == val1){
                idx1 = i;
                found1 = true;
            }
            if(data[i] == val2){
                idx2 = i;
                found2 = true;
            }
        }
        if(!found1 || !found2 ){
           std::cout << "Ein oder beide Elemente konnten nicht gefunden werden!" << std::endl;
           return;
        }
        T tmp = data[idx1];
        data[idx1] = data[idx2];
        data[idx2] = tmp;

    }

private:
    T* data;
    void ensure_size(){
        if(size == current_size){
            current_size*=2;
            T* old = data;
            data = new T[current_size];
            for(int i=0; i < size; i++){
                data[i] = old[i];
            }
            delete old;
        }
    }
    int size;
    int current_size;

};


#endif //ALGORITHMS_STACK_H
