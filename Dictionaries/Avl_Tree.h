//
// Created by Sebastian Kaeser on 28.02.22.
//

#ifndef CPP_ALGORITHMS_AVL_TREE_H
#define CPP_ALGORITHMS_AVL_TREE_H
#include "BinaryTreeDict.h"

template<typename K,  typename V>
struct aNode{
    aNode<K,V> *left;
    aNode<K,V> *right;
    K key;
    V value;
    int height;
    aNode(K Key, V Value){
        this->left = nullptr;
        this->right = nullptr;
        this->key = Key;
        this->value = Value;
        height = 0;
    }
    aNode();
};

template<typename K, typename V>
class AvlTree{
public:

    AvlTree(){
        root = nullptr;
        size = 0;
    }
    V search(K key){
        return searchR(key,root);
    }
    void insert(K key, V value){
        root = insertR(key,value,root);
    }

    void remove(K key){
        root = removeR(key,root);
    }

    int get_size(){
        return this->size;
    }




private:
   aNode<K,V> *root;
    int size = 0;

    int getHeight(aNode<K,V>* p){
        if(p == nullptr){
            return -1;
        } else {
            return p->height;
        }
    }

    int getBalance(aNode<K,V>* p){
        if(p == nullptr){
            return 0;
        } else{
            return getHeight(p->right) - getHeight(p->left);
        }
    }

    aNode<K,V>* balance(aNode<K,V>* p){
        if(p == nullptr){
            return nullptr;
        }
        p->height = std::max(getHeight(p->left), getHeight(p->right)) + 1;
        if(getBalance(p) == -2){
            if(getBalance(p->left) <= 0){
                p = rotateRight(p);
            } else {
                p = rotateLeftRight(p);
            }
        } else if(getBalance(p) == 2){
            if(getBalance(p->right) >= 0){
                p = rotateLeft(p);
            }else {
                p = rotateRightLeft(p);
            }
        }
        return p;
    }

    aNode<K,V>* rotateRight(aNode<K,V>* p){
        assert(p->left != nullptr);
        aNode<K,V>* q = p->left;
        p->left = q->right;
        q->right = p;
        p->height = std::max(getHeight(p->left), getHeight(p->right)) +1;
        q->height = std::max(getHeight(q->left), getHeight(q->right)) +1;
        return q;
    }

    aNode<K,V>* rotateLeft(aNode<K,V>* p){
        assert(p->right != nullptr);
        aNode<K,V>* q = p->right;
        p->right = q->left;
        q->left = p;
        p->height = std::max(getHeight(p->left), getHeight(p->right)) +1;
        q->height = std::max(getHeight(q->left), getHeight(q->right)) +1;
        return q;

    }

    aNode<K,V>* rotateLeftRight(aNode<K,V>* p){
        assert(p->left != nullptr);
        p->left = rotateLeft(p->left);
        return rotateRight(p);
    }

    aNode<K,V>* rotateRightLeft(aNode<K,V>* p){
        assert(p->right != nullptr);
        p->right = rotateRight(p->right);
        return rotateLeft(p);
    }



    aNode<K,V>* insertR(K key, V value, aNode<K,V>* p){
        if(p == nullptr){
            p = new aNode<K,V>(key,value);
        } else if(key < p->key){
            p->left =  insertR(key,value,p->left);
        } else if(key > p->key){
            p->right = insertR(key,value,p->right);
        }
        p = balance(p);
        return p;
    }

    V searchR(K key, aNode<K,V>* p){
        if(p == nullptr){
            std::cout << "[ERROR] No Such Element" << std::endl;
            exit(1);
        } else if(key < p->key){
            return searchR(key,p->left);
        } else if(key > p->key){
            return searchR(key,p->right);
        } else {
            return p->value;
        }
    }

    aNode<K,V>* removeR(K key, aNode<K,V>* p){
        if(p == nullptr){
            p = nullptr;
        }else if(key > p->key){
            p->right = removeR(key,p->right);
        }else if(key < p->key){
            p->left = removeR(key,p->left);
        }else {
            if(p->left == nullptr || p->right == nullptr){
                p = (p->left != nullptr) ? p->left : p->right;
            }else {
                getMin(p->right,p);
                p->right = removeR(p->key,p->right);
            }
        }
        return p;
    }

    void getMin(aNode<K,V>* p,aNode<K,V>*self){
        assert(p != nullptr);
        while(p->left != nullptr){
            p = p->left;
        }
        self->key = p->key;
        self->value = p->value;
    }


};



#endif //CPP_ALGORITHMS_AVL_TREE_H
