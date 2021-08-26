#include <iostream>
#include "LinkedList.h"
#include "Arrays.h"
#include <cstdio>
#include <cstdint>

int main() {

    Array_* arr = new Array_();
    arr->add(0);
    arr->add(10);
    arr->add(20);
    arr->add(30);


    Array_* arr2 = new Array_();
    arr2->add(1);
    arr2->add(2);
    arr2->add(3);


    arr->append(*arr2);

    std::cout << *arr << std::endl;

    return 0;
}
