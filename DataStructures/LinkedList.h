//
// Created by Sebastian Kaeser on 24.08.21.
//

#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H
#include <iostream>

#define ERR 0xf32



template<typename T>
struct Node
{
    Node* next;
    T data;
    Node(T val,Node* next){
        this->next = next;
        this->data = val;
    }
    Node(T val){
        this->data = val;
        this->next = nullptr;
    }
};



template<typename T>
class LinkedList_ {
public:
    LinkedList_(){
        this->clear();
        //std::cout << "[STATUS] " << "List created!" << std::endl;
    }
    void clear(){
        this->size = 0;
        this->head = nullptr;
    }
    int get_size() const {
        return this->size;
    }
    bool isEmpty() const{
        return this->size == 0;
    }
    void add(T value){
        if(head == nullptr){
            head = new Node<T>(value, nullptr);
            //std::cout << "Allocated new Node Addr: " << head << std::endl;
            size++;
            return;
        }
        Node<T> *p = head;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = new Node<T>(value,nullptr);
        //std::cout << "Allocated new Node Addr: " << p->next << std::endl;
        size++;

    }
    T set(int idx, T value){
        int old;
        if(idx > size || idx < 0){
            std::cout << "Index out of Bounds" << std::endl;
            return -1;
        }
        if(head == nullptr){
            std::cout << "List is empty" << std::endl;
            return -2;
        }
        Node<T> *p = head;
        for(int i=0; i < idx; i++){
            p = p->next;
        }
        old = p->data;
        p->data = value;
        return old;
    }
    T* get(int idx) const {
        if(idx < 0 || idx > size){
            return nullptr;
        }
        Node<T> *p = head;
        for(int i=0; i < idx;i++){
           p = p->next;
        }
        return &p->data;
    }
    int remove_idx(int idx){
        if(idx > size || idx < 0){
            std::cout << "Index out of Bounds" << std::endl;
            return -3;
        }
        if(this->size == 0){
           return -2;
        }
        if(this->size == 1){
            clear();
            return -1;
        }
        if(idx == 0){
            auto *p = head;
            head = head->next;
            delete p;
            size--;
            return 1;
        }
        Node<T> *p = head;
        for(int i=0; i < idx; i++){
            p = p->next;
        }
        Node<T> *tmp = p->next;
        p->next = p->next->next;
        T old = tmp->data;
        delete tmp;
        size--;
        return 0;
    }
     bool remove(T value){
        if(head == nullptr){
            return false;
        }
        Node<T> *p = head;
        while(p->next != nullptr){
            if(p->next->data == value){
                Node<T> *tmp = p->next;
                p->next = p->next->next;
                delete tmp;
                return true;
            }
            p = p->next;
        }
        return false;

    }
    friend std::ostream& operator<<(std::ostream& os,LinkedList_& ll){
        os << "{ ";
        Node<T> *p = ll.head;
        while (p != nullptr)
        {
            os << p->data << ", ";
            p = p->next;
        }
        os << "}, size=" << ll.size;
        return os;
    }
    friend std::istream& operator>>(std::istream& is,LinkedList_& ll){
        T x;
        is >> x;

        ll.add(x);
        return is;
    }


    ////////////////////// OPERATORS

    T* operator[](int idx){
        return this->get(idx);
    }

    void operator+=(T e){
        this->add(e);
    }


    LinkedList_<T> operator+(T e){
        auto tmp = LinkedList_<T>(*this);
        tmp.add(e);
        return tmp;
    }

    void operator-=(int e){
        this->remove_idx(e);
    }


    LinkedList_<T> operator-(T e){
        auto tmp = LinkedList_<T>(*this);
        tmp.remove(e);
        return tmp;
    }



    bool operator==(LinkedList_<T>& arr2){
        if(this == &arr2){
            return true;
        }
        for(int i=0; i < size; i++){
            if(*(arr2.get(i)) != *(this->get(i))){
                std::cout << *(this->get(i)) << " != " << arr2[i] << std::endl;
                return false;
            }
        }
        return true;
    }

    bool operator!=(LinkedList_& arr2){
        if(this == &arr2){
            return false;
        }
        for(int i=0; i < size; i++){
            if(arr2.get(i) != this->get(i)){
                return true;
            }
        }
        return false;
    }



    ////////////////////// RULE OF FIVE

    ~LinkedList_(){
        Node<T>* tmp;
        while(head != nullptr){
            tmp = head;
            head = head->next;
            //std::cout << "Free Node Addr: " << tmp << std::endl;
            delete tmp;
        }
    }

    LinkedList_(const LinkedList_& ll){
        this->clear();
        for(int i=0; i < ll.size; i++){
            auto obj =  *(ll.get(i));
            this->add(obj);
        }
    }

    LinkedList_(LinkedList_&& ll){
       this->clear();
       for(int i=0; i< ll.size; i++){
           auto obj = *(ll.get(i));
           this->add(obj);
       }
    }

    LinkedList_& operator=(const LinkedList_& ll){
        this->clear();
        for(int i=0; i< ll.size; i++){
            auto obj = *(ll.get(i));
            this->add(obj);
        }
        return *this;
    }

    LinkedList_& operator=(LinkedList_&& ll){
        this->clear();
        for(int i=0; i< ll.size; i++){
            auto obj = *(ll.get(i));
            this->add(obj);
        }
        return *this;
    }




private:
    Node<T>* head;
    int size;
};

std::istream& operator<<(std::istream&,int&);






#endif //ALGORITHMS_LINKEDLIST_H
