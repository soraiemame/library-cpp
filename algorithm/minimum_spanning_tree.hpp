#ifndef SORAIE_MST
#define SORAIE_MST

#include <vector>
#include <algorithm>

#include "../data-structure/unionfind.hpp"
#include "../utils/graph_alias.hpp"

template<class T>
std::pair<T,std::vector<edge2<T>>> minimum_spanning_tree(const std::vector<edge2<T>> &_es,bool sorted = false){
    std::vector<edge2<T>> es = _es;
    if(!sorted)std::sort(es.begin(),es.end(),[](const edge2<T> a,const edge2<T> b){return a.cost < b.cost;});
    int n = es.size();
    std::pair<T,std::vector<edge2<T>>> res;
    UnionFind UF(n);
    for(edge2<T>& e : es){
        if(!UF.same(e.from,e.to)){
            res.first += e.cost;
            res.second.push_back(e);
        }
    }
    return res;
}

#endif /*SORAIE_MST*/