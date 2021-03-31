#ifndef SORAIE_GRAPH_ALIAS
#define SORAIE_GRAPH_ALIAS

#include <iostream>

template<class T = long long>
struct edge{
    int from,to;T cost;
    edge(){}
    edge(int to,T cost):from(-1),to(to),cost(cost){}
    edge(int from,int to,T cost):from(from),to(to),cost(cost){}
    friend std::ostream &operator<<(std::ostream &os,const edge& a){
        if(a.from == -1)return os << "{" << a.to << "," << a.cost << "}";
        else return os << "{" << a.from << "->" << a.to << "," << a.cost << "}";
    }
};

#endif /*SORAIE_GRAPH_ALIAS*/