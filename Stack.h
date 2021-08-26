//
// Created by Sebastian Kaeser on 26.08.21.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H


class Stack_ {
public:
    Stack_();
    void clear();
    int get_size();
    bool isEmpty();
    void push(int);
    int peek();
    int pop();
    void insert(int,int);
    void swap_int(int,int);

private:
    int* data;
    int size;

};


#endif //ALGORITHMS_STACK_H
