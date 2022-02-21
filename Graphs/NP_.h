//
// Created by Sebastian Kaeser on 06.01.22.
//

#ifndef CPP_ALGORITHMS_NP__H
#define CPP_ALGORITHMS_NP__H



class NP_ {
public:
    static void bongoSort(int *arr,int len){
        srand(time(NULL));
        int sorted  = 0;
        while(!sorted){
            for(int i=0; i < len;i++){
                arr[i] = rand() % 100;
            }
            sorted = 1;
            for(int i=0; i < len-1;i++){
                if(arr[i] >= arr[i+1]) {
                    sorted = 0;
                }
            }

        }
    }

};


#endif //CPP_ALGORITHMS_NP__H
