#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2842"

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#include "../data-structure/SegTree2D.hpp"

int op(int a,int b){ return a + b; }
int e(){ return 0; }

int main(){
    int H,W,T,Q;
    std::cin >> H >> W >> T >> Q;
    SegTree2D<int,op,e> st1(H,W),st2(H,W);
    std::vector<std::tuple<int,int,int,int,int,int>> qs(Q);
    std::queue<std::tuple<int,int,int,int>> que;
    for(int i = 0;i < Q;i++){
        int t,c,h1,w1;
        std::cin >> t >> c >> h1 >> w1;
        h1--; w1--;
        int h2 = -1,w2 = -1;
        if(c == 2){
            std::cin >> h2 >> w2;
        }
        if(c == 0)que.emplace(t,c,h1,w1);
        qs[i] = std::make_tuple(t,c,h1,w1,h2,w2);
    }
    for(auto [t,c,h1,w1,h2,w2] : qs){
        while(!que.empty() && std::get<0>(que.front()) <= t - T){
            int h3 = std::get<2>(que.front()),w3 = std::get<3>(que.front());
            if(st1.get(h3,w3) == 1){
                st1.set(h3,w3,0);
                st2.set(h3,w3,1);
            }
            que.pop();
        }
        if(c == 0){
            if(st1.get(h1,w1) == 0 && st2.get(h1,w1) == 0){
                st1.set(h1,w1,1);
            }
        }
        else if(c == 1){
            if(st2.get(h1,w1) == 1){
                st2.set(h1,w1,0);
            }
        }
        else{
            std::cout << st2.prod(h1,w1,h2,w2) << " " << st1.prod(h1,w1,h2,w2) << "\n";
        }
    }
}
