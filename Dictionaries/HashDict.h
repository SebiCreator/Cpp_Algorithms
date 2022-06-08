//
// Created by Sebastian Kaeser on 03.01.22.
//

#ifndef CPP_ALGORITHMS_HASHDICT_H
#define CPP_ALGORITHMS_HASHDICT_H

#include <string>
#include "../DataStructures/LinkedList.h"
#include "Entry.h"
#include <cmath>

#define DEF_CAP 5


template<typename K, typename V>
class HashDict {
public:
    HashDict() {
        clear();
    }

    Entry<K, V> *search(K key) {
        int hash = this->hash(key);
        for (int i = 0; i < data[hash].get_size(); i++) {
            if (data[hash].get(i)->key == key) {
                //std::cout << "Found " << key << " Value: " << data[hash].get(i)->value <<  std::endl;
                return data[hash].get(i);
            }

        }

        return nullptr;
    }

    void insert(K key, V value) {
        auto *res = this->search(key);

        if (res == nullptr) {
            double threshold = 2;
            if (this->getFill() > threshold) {
                this->increaseSize();
            }
            auto tmp = Entry<K, V>(key, value);
            int hash = this->hash(key);
            this->data[hash].add(tmp);
            this->size++;
            return;
        } else {
            res->key = key;
            res->value = value;
            return;
        }
    }

    void show() {
        for (int i = 0; i < data_len; i++) {
            std::cout << "[[  ID:" << i << "  " << data[i] << "  ]]" << std::endl;
        }
    }

    void remove(K key) {
        int hash = this->hash(key);
        //std::cout << "[REMOVE_START] Key: with " << key << " Hash: " << hash << std::endl;
        //std::cout << "[...]Bucket Lenght: " << this->data[hash].get_size() << std::endl;

        for (int i = 0; i < this->data[hash].get_size(); i++) {
            //std::cout << "[...]Current Key: " << this->data[hash].get(i)->key << " ?= " << key << std::endl;
            if (this->data[hash].get(i)->key == key) {
                int value = this->data[hash].get(i)->value;
                int rv = this->data[hash].remove_idx(i);
                //std::cout << "[REMOVE_END] FOUND ENTRY(rv=" << rv << ",value=" << value << ")\n" << std::endl;
                return;
            }
        }
        //std::cout << "[REMOVE_END] No Such Key\n" << std::endl;
    }

    int get_size() {
        return this->size;
    }

    double getFill() {
        double total = 0;
        for (int i = 0; i < data_len; i++) {
            total += this->data[i].get_size();
        }
        total /= data_len;
        return total;
    }

    void clear() {
        size = 0;
        data_len = DEF_CAP;
        data = new LinkedList_<Entry<K, V> >[data_len];
    }

    bool containsKey(K key) {
        if (this->search(key) == nullptr) {
            return false;
        }
        return true;
    }

    /*int hash = this->hash(key);
    for(int i=0; i < data[hash].get_size();i++){
        if(data[hash].get(i)->key == key){
            //std::cout << "Found " << key << " Value: " << data[hash].get(i)->value <<  std::endl;
            return data[hash].get(i);
        }

    }*/

    LinkedList_<K> getKeys() {
        auto *ll = new LinkedList_<K>();
        for(auto e: *this){
            ll->add(e->key);
        }
        return *ll;
    }

    LinkedList_<K> getValues() {
        auto *ll = new LinkedList_<K>();
        for(auto e: *this){
            ll->add(e->value);
        }
        return *ll;
    }


    ////////////////////////////// OPERATORS

    Entry<K, V> &operator[](K key) {
        return *(this->search(key));
    }



    ////////////////////////////// RULE OF FIVE

    ~HashDict() {
       delete[] data;
    }

    HashDict(const HashDict &ll) {
        this->clear();
        for (int i = 0; i < data_len; i++) {
            auto obj = ll.data[i];
            for (int j = 0; j < obj.get_size(); j++) {
                K key = obj.get(j)->key;
                V value = obj.get(j)->value;
                this->insert(key, value);
            }
        }
    }

    HashDict(HashDict &&ll) {
        this->clear();
        for (int i = 0; i < data_len; i++) {
            auto obj = ll.data[i];
            for (int j = 0; j < obj.get_size(); j++) {
                K key = obj.get(j)->key;
                V value = obj.get(j)->value;
                this->insert(key, value);
            }
        }
    }

    HashDict &operator=(const HashDict &ll) {
        this->clear();
        for (int i = 0; i < data_len; i++) {
            auto obj = ll.data[i];
            for (int j = 0; j < obj.get_size(); j++) {
                K key = obj.get(j)->key;
                V value = obj.get(j)->value;
                this->insert(key, value);
            }
        }
        return *this;
    }

    HashDict &operator=(HashDict &&ll) {
        this->clear();
        for (int i = 0; i < data_len; i++) {
            auto obj = ll.data[i];
            for (int j = 0; j < obj.get_size(); j++) {
                K key = obj.get(j)->key;
                V value = obj.get(j)->value;
                this->insert(key, value);
            }
        }
        return *this;
    }


public:
    int hash(K Key) {
        std::hash<K> hasher;
        int key = (hasher(Key) % data_len);
        return key;
    }


    void increaseSize() {
        int oldsize = data_len;
        data_len = this->getNewSize();
        auto *tmp = new LinkedList_<Entry<K, V> >[data_len];
        for (int i = 0; i < oldsize; i++) {
            for (int j = 0; j < this->data[i].get_size(); j++) {
                auto obj = this->data[i].get(j);
                int hash = this->hash(obj->key);
                tmp[hash].add(*obj);
            }
        }
        auto *old = data;
        data = tmp;
        delete[] old;
    }

    int modPow(int a, int b, int c) {
        int res = 1;
        for (int i = 0; i < b; i++) {
            res *= a;
            res %= c;
        }
        return res % c;
    }

    bool millerRabin(int num) {
        if (num <= 2) {
            return false;
        }
        if (num % 2 == 0) {
            return false;
        }
        int s = num - 1;
        while (s % 2 == 0) {
            s /= 2;
        }
        srand(time(NULL));
        for (int i = 0; i < 100; i++) {
            int r = rand();
            int a = r % (num - 1) + 1;
            int tmp = s;
            int mod = modPow(a, tmp, num);
            while (tmp != num - 1 && mod != 1 && mod != num - 1) {
                mod = mod * mod % num;
                tmp *= 2;
            }
            if (mod != num - 1 && tmp % 2 == 0) {
                return false;
            }
        }
        return true;


    }

    int getNewSize() {
        int nsize = 2 * data_len;
        while (!this->millerRabin(nsize)) {
            nsize++;
        }
        return nsize;
    }

    Entry<K,V>* getFirst(){
        for(int i=0; i < data_len; i++){
            LinkedList_<Entry<K,V> >* cl = &this->data[i];
            if(cl->get_size() != 0){
                return cl->get(0);
            }
        }
        return nullptr;
    }

    Entry<K,V>* getLast(){
        for(int i=data_len; i > 0; i--){
            LinkedList_<Entry<K,V> >* cl = &this->data[i];
            if(cl->get_size() != 0){
                return cl->get(-1);
            }
        }
        return nullptr;
    }

    double get_distribution() {
        double mean = this->getFill();
        double n = this->data_len;
        double sum = 0.0;
        for (int i = 0; i < this->data_len; i++) {
            double x = this->data[i].get_size();
            sum += std::pow((x - mean), 2);
        }
        double term = 1.0 / (n - 1.0);
        double res = term * sum;
        res = std::sqrt(res);
        return res;
    }

    LinkedList_<Entry<K, V> > *data;
    int size;
    int data_len;

    class iterator {
    public:
        friend class HashDict<K, V>;

        iterator() {
            this->current = nullptr;
        }

        iterator& operator=(const iterator& it){
           this->current = it.current;
           this->e_idx = e_idx;
           this->l_idx = l_idx;
        }

        iterator& operator=(iterator&& it){
            this->current = it.current;
            this->e_idx = e_idx;
            this->l_idx = l_idx;
        }

        iterator(const iterator& it){
            this->current = it.current;
            this->e_idx = e_idx;
            this->l_idx = l_idx;
        }
        iterator(iterator&& it){
            this->current = it.current;
            this->e_idx = e_idx;
            this->l_idx = l_idx;
        }


        iterator(HashDict<K, V> &hd) {
            this->e_idx = 0;
            this->dict = &hd;
            for (int i = 0; i < hd.data_len; i++) {
                LinkedList_<Entry<K, V> > &cl = hd.data[i];
                this->l_idx = i;
                if (cl.get_size() != 0) {
                    this->current = cl.get(e_idx);
                    this->e_idx++;
                    break;
                }
            }
        }

        iterator(HashDict<K, V> &hd,Entry<K,V>* e) {
            this->e_idx = -1;
            this->l_idx = -1;
            this->dict = &hd;
            this->current = e;
        }



        iterator operator++() {

            LinkedList_<Entry<K,V> > *cl = &dict->data[l_idx];

                while(cl->get_size() == e_idx){
                    cl = &dict->data[++l_idx];
                    e_idx = 0;
                    if(l_idx >= dict->data_len){
                        std::cout << "Boom " << std::endl;
                        this->current = dict->getLast();
                        l_idx = -1;
                        e_idx = -1;
                    }
                }
                this->current = cl->get(e_idx);
                e_idx++;
                return *this;
        }

        bool operator!=(const iterator& it) const{
            return (this->l_idx != it.l_idx &&
                    this->e_idx != it.e_idx &&
                    this->current != it.current);
        }

        Entry<K,V>* operator*() const{
            return this->current;
        }

    public:
        HashDict<K,V>* dict;
        Entry<K, V> *current;
        int l_idx;
        int e_idx;


    };

    iterator begin(){
        auto e = iterator(*this);
        return e;
    }

    iterator end(){
        auto e = iterator(*this,this->getLast());
        return e;
    }
};


#endif //CPP_ALGORITHMS_HASHDICT_H
