#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "Arrays.h"
#include "Stack.h"
#include "Queue.h"
#include "ArrayDict.h"
#include <cstdio>
#include <string>
#include "Entry.h"
#include <sys/time.h>
#include <NP_.h>
#include <MeasureT.h>
#include <ctime>
#include <unistd.h>
#include <BinaryTreeDict.h>
#include "BinaryTree.h"



int main() {
    auto *tree = new BinaryTreeDict<int,int>();

    tree->insert(1,1);
    tree->insert(2,2);
    tree->insert(3,3);
    tree->insert(4,4);

    std::cout << "Depth: " <<  tree->getHeight() << std::endl;



}


