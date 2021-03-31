#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include <iostream>
#include <vector>

#include "../../graph/spfa.hpp"

int main(){
    int N,M,S;
    std::cin >> N >> M >> S;
    std::vector<std::vector<edge<>>> G(N);
    for(int i = 0;i < M;i++){
        int a,b;long long c;
        std::cin >> a >> b >> c;
        G[a].push_back({b,c});
    }
    const long long INF = 1LL << 60;
    auto ans = get_dist(G,S,INF);
    if(ans.empty())std::cout << "NEGATIVE CYCLE\n";
    else{
        for(long long &x : ans){
            if(x == INF)std::cout << "INF\n";
            else std::cout << x << "\n";
        }
    }
}