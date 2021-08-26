//
// Created by Sebastian Kaeser on 26.08.21.
//

#define DEF_CAPACITY 32
#include "Stack.h"
#include <iostream>

Stack_::Stack_() {
    this->clear();
}

void Stack_::clear() {
    this->size = 0;
    data = new int[DEF_CAPACITY];
}

int Stack_::get_size() {
    return this->size;
}

bool Stack_::isEmpty() {
    return this->size == 0;
}

void Stack_::push(int value) {
    data[size] = value;
    size++;
}

int Stack_::peek() {
    return data[size-1];
}

int Stack_::pop()
{
    if(this->isEmpty())
    {
        std::cout << "Stack ist leer!" << std::endl;
        return 0;
    }
    int value = data[--size];
    return value;
}

void Stack_::insert(int value,int idx) {
   if(idx < 0 || idx > size)
   {
       std::cout << "Out of Bounds!" << std::endl;
   }
}

void Stack_::swap_int(int idx1, int idx2)
{
    int tmp = data[idx1];
    data[idx1] = data[idx2];
    data[idx2] = data[tmp];
}