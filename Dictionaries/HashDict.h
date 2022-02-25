//
// Created by Sebastian Kaeser on 03.01.22.
//

#ifndef CPP_ALGORITHMS_HASHDICT_H
#define CPP_ALGORITHMS_HASHDICT_H
#include <string>
#include "../DataStructures/LinkedList.h"
#include "Entry.h"

#define DEF_CAP 23
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
          auto *entry = new Entry<K,V>(key,value);
          int hash = this->hash(key);
          data[hash].add(*entry);
          size++;
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
           size = 0;
           data_len = DEF_CAP;
           data = new LinkedList_<Entry<K,V>>[data_len];
   }





public:
     int hash(K key){

      int hash1 = key << 3;
      int hash2 = key >> 2;
      int hash3 = key &= 0x55555;

      return ((hash1 | hash2) ^ hash3) % data_len;
    }
    void increaseSize();
    int modPow(int,int,int);
    bool millerRabin(int);
    int getNewSize();
    LinkedList_<Entry<K,V>> *data;
    int size;
    int data_len;
};





#endif //CPP_ALGORITHMS_HASHDICT_H
