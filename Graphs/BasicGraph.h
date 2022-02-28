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
        if(!containsVertex(v1) || !containsVertex(v2)){
            return false;
        }
        return succ->search(v1)->value.search(v2)->value != ;
    }

    bool addVertex(V v){
        if(containsVertex(v)){
            return false;
        }
        succ->insert(v,HashDict<V,double>());
        pred->insert(v,HashDict<V,double>());
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
           succ->search(v1)->value.search(v2)->value = weight;
           pred->search(v2)->value.search(v1)->value = weight;
           return false;
        }
        succ->search(v1)->value.insert(v2,weight);
        pred->search(v2)->value.insert(v1,weight);
        return true;

    }

    bool addEdge(V v1, V v2){
        return addEdge(v1,v2,1);
    }


private:
   HashDict<V,HashDict<V,double>>* pred;
   HashDict<V,HashDict<V,double>>* succ;
   int numberEdge;
   int numberVertex;

};

#endif //CPP_ALGORITHMS_BASICGRAPH_H
