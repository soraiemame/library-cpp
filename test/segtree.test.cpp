#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include <iostream>
#include <algorithm>

#include "../data-structure/segtree.hpp"

using S = int;
S op(S a,S b){return std::min(a,b);}
S e(){return INT32_MAX;}

int main(){
    int N,Q;
    std::cin >> N >> Q;
    segtree<S,op,e> st(N);
    for(int i = 0;i < Q;i++){
        int t,a,b;
        std::cin >> t >> a >> b;
        if(t == 0){
            st.set(a,b);
        }
        if(t == 1){
            std::cout << st.prod(a,b + 1) << "\n";
        }
    }
}