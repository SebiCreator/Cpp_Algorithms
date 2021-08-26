//
// Created by Sebastian Kaeser on 26.08.21.
//

#include "Arrays.h"
#include <iostream>

Array_::Array_() {
    Array_::clear();
}

Array_::Array_(Array_& arr) {
    this->append(arr);
}

void Array_::clear() {
    this->size = 0;
    this->data = new int[DEF_CAPACITY];
    this->current_len = DEF_CAPACITY;
}

int Array_::get_size() {
    return this->size;
}

bool Array_::isEmpty() {
    return this->size == 0;
}

void Array_::add(int x, int idx) {
    if (idx < 0 || idx > this->size) {
        std::cout << "Index muss größer 0 sein und darf die Array-Grenzen nicht überschreiten!" << std::endl;
        return;
    }
    if (current_len == size) {
        int *tmp = new int[current_len * 2];
        for (int i = 0; i < current_len; i++) {
            tmp[i] = data[i];
        }
        data = tmp;
        current_len *= 2;
    }
    for(int i=size; i > idx; i--)
    {
        data[i] = data[i-1];
    }
    data[idx] = x;
    this->size++;
}

void Array_::add(int x) {
    add(x, this->size);
}

int Array_::set(int x, int idx) {
    if (idx < 0 || idx > size) {
        std::cout << "Index muss größer 0 sein und darf die Array-Grenzen nicht überschreiten!" << std::endl;
        return 0;
    }
    int old = data[idx];
    data[idx] = x;
    return old;
}

int Array_::get(int idx) {
    if (idx < 0 || idx > size) {
        std::cout << "Index muss größer 0 sein und darf die Array-Grenzen nicht überschreiten!" << std::endl;
        return 0;
    }
    return data[idx];
}

int Array_::remove(int idx)
{
    int old = data[idx];
    for(int i=this->size-1; i > idx; i--)
    {
        data[i-1] = data[i];
    }


    (this->size)--;
    return old;
}

void Array_::append(Array_& arr)
{
    for(int i=0; i < arr.size; i++)
    {
        this->add(arr.get(i));
    }
}

std::ostream& operator<<(std::ostream& os, Array_& arr)
{
    os << "{ ";
    for(int i=0; i < arr.size; i++)
    {
        os << arr.data[i] << ", ";
    }
    os << " }, size = ";
    os << arr.size << std::endl;
    return os;
}









