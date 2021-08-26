//
// Created by Sebastian Kaeser on 24.08.21.
//

#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H
#include <iostream>




struct Node
{
    Node* next;
    int data;
    Node(int,Node*);
};

class LinkedList_ {
public:
    LinkedList_();
    void clear();
    int get_size();
    bool isEmpty();
    void add(int);
    int set(int,int);
    int get(int);
    void remove(int);
    friend std::ostream& operator<<(std::ostream&,LinkedList_&);
    friend std::istream& operator>>(std::istream&,LinkedList_&);
private:
    Node* head;
    int size;



};

std::istream& operator<<(std::istream&,int&);






#endif //ALGORITHMS_LINKEDLIST_H
