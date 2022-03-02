//
// Created by Sebastian Kaeser on 28.02.22.
//

#ifndef CPP_ALGORITHMS_BASICGRAPH_H
#define CPP_ALGORITHMS_BASICGRAPH_H

#include "../Dictionaries/HashDict.h"

template<typename V>
class Graph{
public:
    Graph(){
        clear();
    }
    void clear(){
        pred = new HashDict<V,HashDict<V,double>>;
        succ = new HashDict<V,HashDict<V,double>>;
    }

    bool containsVertex(V v){
        return (succ->search(v) != nullptr && pred->search(v) != nullptr);
    }

    bool containsEdge(V v1, V v2){
        return succ->search(v1)->value.containsKey(v2) &&
        pred->search(v2)->value.containsKey(v1);
    }

    bool addVertex(V v){
        if(containsVertex(v)){
            return false;
        }
        succ->insert(v,HashDict<V,double>());
        pred->insert(v,HashDict<V,double>());
        numberVertex++;
        return true;
    }

    bool addEdge(V v1, V v2,double weight){
        if(!containsVertex(v1)){
            addVertex(v1);
        }
        if(!containsVertex(v2)){
            addVertex(v2);
        }
        if(containsEdge(v1,v2)){
            std::cout << "Edege exists" << std::endl;
           succ->search(v1)->value.search(v2)->value = weight;
           pred->search(v2)->value.search(v1)->value = weight;
           return false;
        }
        std::cout << "Create new Edge" << std::endl;
        succ->search(v1)->value.insert(v2,weight);
        pred->search(v2)->value.insert(v1,weight);
        numberEdge++;
        return true;

    }

    bool addEdge(V v1, V v2){
        return addEdge(v1,v2,1);
    }

    double getWeight(V v, V v2){
        return succ->search(v)->value.search(v2)->value;
    }

    int getOutDegree(V v){
        return succ->search(v)->value.get_size();
    }

    int getInDegree(V v){
        return pred->search(v)->value.get_size();
    }

    LinkedList_<V> getVertexSet(){
        return this->succ->getKeySet();
    }

    LinkedList_<V> getPredSet(V v){
       auto ks = this->pred->search(v)->value.getKeySet();
       return ks;
    }

    LinkedList_<V> getSuccSet(V v){
        auto ks = this->succ->search(v)->value.getKeySet();
        return ks;
    }

    int getVertexNum(){
        return this->getVertexSet().get_size();
    }

    int getNumEdger(){
        return numberEdge;
    }

    Graph<V> invert(){
        auto *graph = new Graph<V>();
        graph->succ = this->pred;
        graph->pred = this->succ;

        std::cout << graph->succ << " == " << this->pred << std::endl;
        std::cout << graph->pred<< " == " << this->succ << std::endl;
    }

    std::ostream& operator<<(std::ostream& os){

    }


    void show_list(V k){
        std::cout << "Value: " << k << std::endl;
       std::cout << "\nPredecessor" << std::endl;
       this->pred->search(k)->value.show();

        std::cout << "\nSucessor" << std::endl;
        this->succ->search(k)->value.show();

        std::cout << "\n" << std::endl;
    }

public:
   HashDict<V,HashDict<V,double>>* pred;
   HashDict<V,HashDict<V,double>>* succ;
   int numberEdge;
   int numberVertex;

};

#endif //CPP_ALGORITHMS_BASICGRAPH_H
