//
// Created by Sebastian Kaeser on 01.03.22.
//

#ifndef CPP_ALGORITHMS_FUNCTIONTIMER_H
#define CPP_ALGORITHMS_FUNCTIONTIMER_H
#include "MeasureT.h"


template<typename T>
void linFuncTester(void*(func)(T),int iterations){
   auto *timer = new MeasureT();
   timer->start();
   for(int i=0; i < iterations; i++){
       func(i);
   }
   timer->stop();
   timer->print();
   delete timer;
}

template<typename K, typename V>
int linFuncTester(void*(func)(K,V),int iterations){
    auto *timer = new MeasureT();
    timer->start();
    for(int i=0; i < iterations; i++){
        func(i,i*i);
    }
    timer->stop();
    timer->print();
    delete timer;
}

template<typename T>
int linFuncTester(T*(func)(),int iterations){
    auto *timer = new MeasureT();
    timer->start();
    for(int i=0; i < iterations; i++){
        func(i,i*i);
    }
    timer->stop();
    timer->print();
    delete timer;
}



//############################### RANDOM #################################


template<typename T>
void randFuncTester(void*(func)(T),int iterations){
    auto *timer = new MeasureT();
    srand(time(NULL));
    timer->start();
    for(int i=0; i < iterations; i++){
        func(rand()%iterations);
    }
    timer->stop();
    timer->print();
    delete timer;
}

template<typename K, typename V>
int randFuncTester(void*(func)(K,V),int iterations){
    auto *timer = new MeasureT();
    srand(time(NULL));
    timer->start();
    for(int i=0; i < iterations; i++){
        func(rand()%iterations,rand()%iterations);
    }
    timer->stop();
    timer->print();
    delete timer;
}





#endif //CPP_ALGORITHMS_FUNCTIONTIMER_H
