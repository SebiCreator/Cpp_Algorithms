#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList * list = new LinkedList();
    list->addNode(10);
    list->addNode(20);
    list->addNode(30);
    list->traverse();
    return 0;
}
