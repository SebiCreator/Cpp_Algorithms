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

   Entry<K,V>* search(K key){
        int hash = this->hash(key);
        for(int i=0; i < data[hash].get_size();i++){
            if(data[hash].get(i)->key == key){
                std::cout << "Found " << key << " Value: " << data[hash].get(i)->value <<  std::endl;
                auto tmp = this->data[hash].get(i);
                return data[hash].get(i);
            }
        }
   }

   V* insert(K key, V value){
      auto tmp = Entry<K,V>(key,value);
      int hash = this->hash(key);
      std::cout << "[INSERT]Key:" << key << ", Hash: " << hash << std::endl;
      this->data[hash].add(tmp);
      return nullptr;
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
      int hash3 = key & 0x55555;

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
