//
// Created by Sebastian Kaeser on 03.01.22.
//

#ifndef CPP_ALGORITHMS_ARRAYDICT_H
#define CPP_ALGORITHMS_ARRAYDICT_H

#include <string>
#include "Entry.h"
#include <typeinfo>

#define string std::string
#define DEF_CAP 16

template<typename K,typename V>
class ArrayDict {
public:
    ArrayDict(){
        this->clear();
    }
    void clear(){
        this->size = 0;
        this->data = new Entry<K, V>[DEF_CAP];
        this->current_size = DEF_CAP;
    }
    V search(K key){
       int i = search_key(key);
       if(i == -1){
           throw std::out_of_range("Index out of Bounds!");
       }
       //TODO: Why cant get value ?
       return data[i].value;
    }
    void insert(K key ,V value){
        int i = search_key(key);
        if(i == -1){
            //TODO: ERROR
            auto tmp = new Entry<K,V>(key,value);
            data[size] = *tmp;
            //data[size].key = value;
            //data[size].key = key;
            size++;
            return;
        }
        V old = data[i].value;
        data[i].value = value;
        data[i].key = key;
        return;
    }
    V remove(K key){
        int i = search_key(key);
        if(i == -1){
            throw std::exception();
        }
        V old = data[i].value;
        for(int j=i; j < size-1; j++){
            data[j] = data[j+1];
        }
        size--;
    }
    int get_size(){
        return this->size;
    }

    V operator[](K key){
        return search(key);
    }

private:
    int search_key(K key){
        for(int i=0; i < size; i++){
            if(data[i].key == key){
                return i;
            }
        }
        return -1;
    }
    int ensure_size(){
        if(this->size == current_size){
            current_size *=2;
            Entry<K,V> *tmp = new Entry<K, V>[current_size]();
            for(int i=0; i < size; i++){
                tmp[i] = data[i];
            }
            Entry<K,V> *oldptr = data;
            data = tmp;
            delete oldptr;
        }
    }

    int size;
    int current_size;
    Entry<K,V> *data;
};


#endif //CPP_ALGORITHMS_ARRAYDICT_H
