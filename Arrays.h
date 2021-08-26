//
// Created by Sebastian Kaeser on 26.08.21.
//

#ifndef ALGORITHMS_ARRAYS_H
#define ALGORITHMS_ARRAYS_H

#include <iostream>


class Array_
{
public:
    Array_();
    Array_(Array_&);
    void clear();
    int get_size();
    bool isEmpty();
    void add(int);
    void add(int,int);
    int set(int,int);
    int get(int);
    int remove(int);
    friend std::ostream& operator<< (std::ostream&,Array_&);
    void append(Array_&);

private:
    static const int DEF_CAPACITY = 32;
    int size;
    int* data;
    int current_len;
};


#endif //ALGORITHMS_ARRAYS_H
