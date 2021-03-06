#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../data-structure/lazysegtree_utils.hpp"

#include <iostream>

int main(){
    int N,Q;
    std::cin >> N >> Q;
    RSQ_RAQ<long long> ST(N);
    for(int i = 0;i < Q;i++){
        int t;
        std::cin >> t;
        if(t == 0){
            int a,b,c;
            std::cin >> a >> b >> c;
            ST.update(a - 1,b,c);
        }
        else{
            int a,b;
            std::cin >> a >> b;
            std::cout << ST.query(a - 1,b).val << "\n";
        }
    }
}