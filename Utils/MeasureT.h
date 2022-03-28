//
// Created by Sebastian Kaeser on 06.01.22.
//

#ifndef CPP_ALGORITHMS_MEASURET_H
#define CPP_ALGORITHMS_MEASURET_H

#include <ctime>
#include <inttypes.h>


class MeasureT {
private:
    struct timespec startT;
    struct timespec endT;

public:
    time_t sec;
    unsigned long n_sec;
    MeasureT(){
       this->reset();
    };
    void start(){
        clock_gettime(CLOCK_MONOTONIC_RAW,&startT);
    }
    void stop(){
        clock_gettime(CLOCK_MONOTONIC_RAW,&endT);
        if(startT.tv_nsec > endT.tv_nsec){
           sec--;
           endT.tv_nsec += 10e9 - startT.tv_nsec;
        }
        this->sec  += endT.tv_sec - startT.tv_sec;
        this->n_sec += endT.tv_nsec - startT.tv_nsec;
    }
    void print(){
        printf("\nCurrent Time:\n{ Sec: %ld, nsec: %lu }\n",sec,n_sec);
    }
    void printsec(){
       printf("Current Time:\nSeconds: %ld\n",sec);
    }
    void printnsec(){
        printf("Current Time:\nNano-Seconds: %lu\n",n_sec);
    }

    void reset(){
        this->sec = 0;
        this->n_sec = 0;
    }
};


#endif //CPP_ALGORITHMS_MEASURET_H
