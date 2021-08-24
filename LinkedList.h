//
// Created by Sebastian Kaeser on 24.08.21.
//

#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H


class LinkedList {
public:
    class Node
    {
    public:
        Node* next;
        int value;
        Node(Node*,int);
    };
    LinkedList() = default;
    void addNode(int);
    void traverse();
private:
    Node* head;
};





#endif //ALGORITHMS_LINKEDLIST_H
