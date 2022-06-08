//
// Created by Sebastian Kaeser on 31.03.22.
//
#include "../DataStructures/Arrays.h"
#include "../Dictionaries/HashDict.h"

#ifndef CPP_ALGORITHMS_GAMES_H


template<typename T>
HashDict<T>& get_parity(Array_<T>& problem const){
   auto* result = new HashDict<T,T>();
   for(int i=0; i < problem.get_size(); i++){
       for(int j=i; j < problem.get_size(); j++){
           if (problem[j] < problem[i]){
               result->insert(problem[j],problem[i])
           }
       }
   }
   return result

}


class Games{
public:

private:

};

#define CPP_ALGORITHMS_GAMES_H

#endif //CPP_ALGORITHMS_GAMES_H
