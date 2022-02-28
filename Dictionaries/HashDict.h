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
                return data[hash].get(i);
            }

        }

       return nullptr;
   }

   void insert(K key, V value){
       auto *res = this->search(key);

       if(res == nullptr){
           std::cout << "Nullptr: No Entry for this key" << std::endl;
           auto tmp = Entry<K,V>(key,value);
           int hash = this->hash(key);
           std::cout << "[INSERT]Key:" << key << ", Hash: " << hash << std::endl;
           this->data[hash].add(tmp);
           this->size++;
           return;
       } else {
           std::cout << "Key exists " << std::endl;
           res->value = value;
           return;
       }
   }

   void show(){
       for(int i=0; i < data_len;i++){
           std::cout << "[[  ID:" << i << "  " <<  data[i] << "  ]]" << std::endl;
       }
   }

   void remove(K key){
       int hash = this->hash(key);
       //std::cout << "[REMOVE_START] Key: with " << key << " Hash: " << hash << std::endl;
       //std::cout << "[...]Bucket Lenght: " << this->data[hash].get_size() << std::endl;

       for(int i=0; i < this->data[hash].get_size();i++){
           //std::cout << "[...]Current Key: " << this->data[hash].get(i)->key << " ?= " << key << std::endl;
           if(this->data[hash].get(i)->key == key){
               int value = this->data[hash].get(i)->value;
               int rv = this->data[hash].remove_idx(i);
               //std::cout << "[REMOVE_END] FOUND ENTRY(rv=" << rv << ",value=" << value << ")\n" << std::endl;
               return;
           }
       }
       //std::cout << "[REMOVE_END] No Such Key\n" << std::endl;
   }

   int get_size(){
           return this->size;
   }

   double getFill(){
          //TODO:
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
    void increaseSize(){

   }
    int modPow(int,int,int);
    bool millerRabin(int);
    int getNewSize();
    LinkedList_<Entry<K,V>> *data;
    int size;
    int data_len;
};





#endif //CPP_ALGORITHMS_HASHDICT_H
