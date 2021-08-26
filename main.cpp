#include <iostream>
#include "LinkedList.h"
#include "Arrays.h"
#include "Stack.h"
#include <cstdio>
#include <cstdint>

int main() {

    Stack_* s = new Stack_();
    s->push(1);
    s->push(2);
    s->push(3);

    std::cout << s->pop() << std::endl;
    std::cout << s->pop() << std::endl;
    std::cout << s->pop() << std::endl;
    std::cout << s->pop() << std::endl;


    return 0;
}
