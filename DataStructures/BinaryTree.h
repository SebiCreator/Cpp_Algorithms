//
// Created by Sebastian Kaeser on 11.02.22.
//

#ifndef CPP_ALGORITHMS_BINARYTREE_H
#define CPP_ALGORITHMS_BINARYTREE_H




template <typename T>
class BinaryTree{
public:
   BinaryTree(){
      root = nullptr;
      size = 0;
   }

   int insert(T value){
       auto p = root;
       while(p != nullptr){
           if(value > p->value){
               p = p->right;
           }
           if(value < p->value){
               p = p->left;
           }
           if(value == p->value){
               return -1;
           }
       }
       if(value > p->value){
           p->right = new Node<T>(value);
       }else {
           p->left = new Node<T>(value);
       }

   }
private:
    template<typename F>
    class Node{
        Node();
        Node(F Value){
            this->value = value;
            this->right = nullptr;
            this->left = nullptr;
        }
        Node<F> *right;
        Node<F> *left;
        T value;
   };


    Node<T> *root;
    int size;




};

#endif //CPP_ALGORITHMS_BINARYTREE_H
