//
// Created by Sebastian Kaeser on 03.01.22.
//

#ifndef CPP_ALGORITHMS_HASHDICT_H
#define CPP_ALGORITHMS_HASHDICT_H
#include <string>
#include "LinkedList.h"
#include "Entry.h"

#define DEF_CAP 16
#define string std::string




template<typename K, typename V>
class HashDict {
public:
   HashDict(){
       clear();
   }

   V search(K key){
           //TODO
   }

   V insert(K key, V value){
          //TODO 
   }

   V remove(K key){
          //TODO 
   }

   int get_size(){
           //TODO
   }

   double getFill(){
           //TODO
   }

   void clear(){
           //TODO
   }
private:

    int hash(string key);
    void increaseSize();
    int modPow(int,int,int);
    bool millerRabin(int);
    int getNewSize();
    LinkedList_ *data;
    int size;
    int data_len;
};


#endif //CPP_ALGORITHMS_HASHDICT_H
