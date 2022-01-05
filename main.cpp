#include <iostream>
#include "LinkedList.h"
#include "Arrays.h"
#include "Stack.h"
#include "Queue.h"
#include "ArrayDict.h"
#include <cstdio>
#include <string>
#include "Entry.h"




int main() {

    auto ad = new ArrayDict<int,char>();
    ad->insert(10,'e');

    std::cout << ad->search(10) << std::endl;

}
