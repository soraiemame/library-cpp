#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <iostream>
#include <vector>
#include <tuple>

#include "../data-structure/SegTree2DCompressed.hpp"

long long op(long long a,long long b){ return a + b; }
long long e(){ return 0; }

int main(){
    int N,Q;
    std::cin >> N >> Q;
    std::vector<long long> px(N),py(N),pw(N);
    for(int i = 0;i < N;i++)std::cin >> px[i] >> py[i] >> pw[i];
    std::vector<std::tuple<int,int,int,int,int>> qs(Q);
    for(int i = 0;i < Q;i++){
        int t,h1,w1;
        std::cin >> t >> h1 >> w1;
        if(t == 0){
            int w;
            std::cin >> w;
            qs[i] = std::make_tuple(t,h1,w1,w,-1);
            px.emplace_back(h1);
            py.emplace_back(w1);
        }
        else{
            int h2,w2;
            std::cin >> h2 >> w2;
            qs[i] = std::make_tuple(t,h1,w1,h2,w2);
        }
    }
    SegTree2DCompress<long long,op,e> st(px,py);
    for(int i = 0;i < N;i++)st.set(px[i],py[i],st.get(px[i],py[i]) + pw[i]);
    for(auto [t,h1,w1,h2,w2] : qs){
        if(t == 0){
            int w = h2;
            st.set(h1,w1,st.get(h1,w1) + w);
        }
        else{
            std::cout << st.prod(h1,w1,h2,w2) << "\n";
        }
    }
}
