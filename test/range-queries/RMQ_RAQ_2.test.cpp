#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "../../data-structure/lazysegtree_utils.hpp"

#include <iostream>

int main(){
    int N,Q;
    std::cin >> N >> Q;
    RMQ_RAQ<long long> ST(N);
    ST.update(0,N,-ST.get(0));
    for(int i = 0;i < Q;i++){
        int t;
        std::cin >> t;
        if(t == 0){
            int a,b,c;
            std::cin >> a >> b >> c;
            ST.update(a,b + 1,c);
        }
        else{
            int a,b;
            std::cin >> a >> b;
            std::cout << ST.query(a,b + 1) << "\n";
        }
    }
}