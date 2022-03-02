//
// Created by Sebastian Kaeser on 26.08.21.
//

#ifndef ALGORITHMS_ARRAYS_H
#define ALGORITHMS_ARRAYS_H

#include <iostream>
#include <stdexcept>

template<typename T>
class Array_
{
public:
    Array_(){
        this->clear();
    }
    void clear(){
        this->size = 0;
        this->data = new T[DEF_CAPACITY];
        this->current_len = DEF_CAPACITY;
        this->sorted = false;
    }
    int get_size() const {
        return this->size;
    }
    bool isEmpty() const {
        return this->size == 0;
    }
    void add(T value){
       this->ensure_size();
       data[size++] = value;
       this->sorted = false;
    }
    T set(T value, int idx){
        if(idx < 0 || idx > size){
            throw std::out_of_range("Index out of Bounds!");
        }
        T old = data[idx];
        data[idx] = value;
        sorted = false;
        return old;
    }
    T* get (int idx) const {
        if(idx > size || idx < 0){
            std::cout << "UPS";
            return nullptr;
        }
        return &data[idx];
    }
    T remove_idx(int idx){
        if(idx < 0 || idx > size){
            throw std::out_of_range("Index out of Bounds!");
        }

        T old = data[idx];
        for(int i=size-1; i > idx; i--){
            data[i-1] = data[i];
        }

        size--;
        sorted = false;
        return old;

    }

    T& remove_val(T val){

        int idx = -1;
        T old;

        for(int i=0; i< current_len; i++){
            if(data[i] == val){
                idx = i;
                old = data[i];
            }
        }

        if(idx == -1){
            return nullptr;
        }

        for(int i=size-1; i > idx; i--){
            data[i-1] = data[i];
        }

        size--;
        sorted = false;
        return old;

    }
    bool findSeq(T value){
        for(int i=0 ; i < size; i++){
            if(data[i] == value){
                return true;
            }
        }
        return false;
    }
    bool findBin(T value){
        if(!sorted){
            std::cout << "List must be sorted to search binary" << std::endl;
            return false;
        }
        int li = 0,re = size-1;
        while(re >= li){
            int m = (int) (re+li) / 2;
            if(value == data[m]){
                return true;
            } else if(value < data[m]){
                re = m -1;
            } else {
                li = m + 1;
            }
        }
        return false;
    }
    void sort(){
        bool vertauscht;
        for(int i=this->size-1;i >= 1;i--){
            vertauscht = false;
            for(int j=0; j < i;j++){
                if(data[j] > data[j+1]){
                    T tmp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = tmp;
                    vertauscht = true;
                }
            }
            if(!vertauscht){
                break;
            }
        }
        this->sorted = true;
    }
    bool isSorted(){
        return this->isSorted();
    }
    /*friend std::istream operator>>(std::istream& is,T value){
    }*/
    friend std::ostream& operator<< (std::ostream& os,Array_& arr){
        os << "{ ";
        for(int i=0; i < arr.size; i++)
        {
            os << arr.data[i] << ", ";
        }
        os << " }, size = ";
        os << arr.size << std::endl;
        return os;
    }
    void append(Array_& arr){
        for(int i=0; i < arr.size; i++)
        {
            this->add(arr.get(i));
        }

        this->sorted = false;
    }

//////////////////////   OPERATORS


    int& operator [](int i) { return *(data[i]); }

    void operator+=(T e){
       this->add(e);
    }

    Array_<T> operator+(T e){
        Array_<T> tmp = Array_<T>(*this);
        tmp += e;
        return tmp;
    }

    void operator*(int scalar){
        for(int i=0; i < current_len; i++){
            data[i] = data[i] * scalar;
        }
    }

    void operator-(T e){
       this->remove_val(e);
    }

    bool operator==(Array_<T>& arr2){
        for(int i=0; i < current_len; i++){
            if(arr2.get(i) != this->get(i)){
                return false;
            }
        }
        return true;
    }

    bool operator!=(Array_<T>& arr2){
        for(int i=0; i < current_len; i++){
            if(arr2.get(i) != this->get(i)){
                return true;
            }
        }
        return false;
    }

//////////////////////   RULE OF FIVE

    ~Array_(){
        delete data;
    }

    Array_<T>(const Array_<T>& arr2){
        this->clear();
        for(int i=0; i < arr2.current_len; i++){
            auto arg = arr2.data[i];
            this->add(arg);
        }
        this->size = arr2.size;
    }
    Array_<T>(Array_&& arr){
        this->clear();
        this->size = arr.size;
        for(int i=0; i< arr.current_len; i++){
            auto arg = arr.data[i];
            this->add(arg);
        }
    }

    Array_<T>& operator=(const Array_<T>& arr){
        std::cout << "Case B" << std::endl;
        this->clear();
        for(int i=0; i< arr.current_len; i++){
            auto arg = arr.data[i];
            this->add(arg);
        }
        this->size = arr.size;
        return *this;
    }
    Array_<T>& operator=(Array_<T>&& arr) noexcept {
        std::cout << "Case A" << std::endl;
        this->clear();
        for(int i=0; i< arr.current_len; i++){
            auto arg = arr.data[i];
            this->add(arg);
        }
        this->size = arr.size;
        return *this;
    }




private:
    void ensure_size(){
        if(size == current_len){
            T* old = data;
            current_len*=2;
            data = new T[current_len];
            for(int i=0; i< size; i++){
                data[i] = old[i];
            }
            delete old;
        }
    }
    static const int DEF_CAPACITY = 32;
    int size;
    T* data;
    int current_len;
    bool sorted;
};



#endif //ALGORITHMS_ARRAYS_H
