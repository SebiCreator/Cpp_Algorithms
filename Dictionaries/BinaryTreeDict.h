//
// Created by Sebastian Kaeser on 05.01.22.
//

#ifndef CPP_ALGORITHMS_BINARYTREEDICT_H
#define CPP_ALGORITHMS_BINARYTREEDICT_H
#include <cmath>

#include <Queue.h>


template<typename K, typename V>
struct bNode{
     bNode<K,V> *left;
     bNode<K,V> *right;
     K key;
     V value;
     bNode(K Key, V Value){
         this->left = nullptr;
         this->right = nullptr;
         this->key = Key;
         this->value = Value;
     }
     bNode();
};


template<typename K,typename V>
class BinaryTreeDict {
public:
   BinaryTreeDict(){
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

   void preOrder(){
       std::cout << "Pre Order Durchlauf\n{";
       preOrderR(root);
       std::cout << " }\n" << std::endl;
   }

   void postOrder(){
      std::cout << "Post Order Durchlauf\n{";
       postOrderR(root);
       std::cout << "}\n" << std::endl;
   }

   void inOrder(){
       std::cout << "In Order Durchlauf\n{";
       inOrderR(root);
       std::cout << "}\n" << std::endl;
   }

   void levelOrder(){
      std::cout << "Level Order Durchlauf\n{" ;
      levelOrderR(root);
      std::cout << "}\n" << std::endl;
   }


   int getHeight(){
       return getDepthR(root);
   }


private:
   bNode<K,V>* root;
   int size;

   int getDepthR(bNode<K,V> *p){
       if(root == nullptr){
           return 0;
       }
       int leftHeight = 0, rightHight = 0;
       if(p->right != nullptr){
           leftHeight = getDepthR(p->left);
       }
       if(p->left != nullptr){
           rightHight = getDepthR(p->right);
       }
       return max(leftHeight,rightHight) + 1;
   }

   int max(int left,int right){
       if(left > right){
           return left;
       } else {
           return right;
       }
   }

   void levelOrderR(bNode<K,V>* p){
      auto* queue = new Queue_<bNode<K,V>*>();
      queue->insert(p);

      while(queue->get_size() != 0){
          bNode<K,V>* q = queue->remove();
          if(q != nullptr){
              std::cout << "(" << q->key << "," << q->value << "),";
              queue->insert(q->left);
              queue->insert(q->right);
          }
      }
   }

   void inOrderR(bNode<K,V>* p){
      if(p != nullptr) {
          inOrderR(p->left);
          std::cout << "(" << p->key << "," << p->value << "),";
          inOrderR(p->right);
      }
   }

   void postOrderR(bNode<K,V>* p){
      if(p != nullptr) {
          postOrderR(p->left);
          postOrderR(p->right);
          std::cout << "(" << p->key << "," << p->value << "),";
      }
   }

   void preOrderR(bNode<K,V>* p){
       if(p != nullptr){
           std::cout << "(" << p->key << "," << p->value << "),";
           preOrderR(p->left);
           preOrderR(p->right);
       }
   }

   bNode<K,V>* removeR(K key, bNode<K,V>* p){
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

   void getMin(bNode<K,V>* p,bNode<K,V>*self){
      assert(p != nullptr);
      while(p->left != nullptr){
          p = p->left;
      }
      self->key = p->key;
      self->value = p->value;
   }




   bNode<K,V>* insertR(K key, V value, bNode<K,V>* p){
       if(p == nullptr){
           p = new bNode<K,V>(key,value);
       } else if(key < p->key){
           p->left =  insertR(key,value,p->left);
       } else if(key > p->key){
           p->right = insertR(key,value,p->right);
       }
       return p;
   }
   V searchR(K key, bNode<K,V>* p){
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
};




#endif //CPP_ALGORITHMS_BINARYTREEDICT_H
