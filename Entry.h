//
// Created by Sebastian Kaeser on 05.01.22.
//

#ifndef CPP_ALGORITHMS_ENTRY_H
#define CPP_ALGORITHMS_ENTRY_H

template<typename K,typename V>
struct Entry {
public:
    K key;
    V value;
    Entry(K Key,V Value) {
       this->key = Key;
       this->value = Value;
    }
    Entry(){}
    V getValue(){
        return value;
    }
    K getKey(){
        return key;
    }
};


#endif //CPP_ALGORITHMS_ENTRY_H
