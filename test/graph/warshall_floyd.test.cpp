#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include <iostream>
#include <algorithm>
#include <vector>

#include "../../graph/warshall_floyd.hpp"

int main(){
    const long long INF = 1LL << 60;
    int N,M;
    std::cin >> N >> M;
    std::vector<std::vector<long long>> G(N,std::vector<long long>(N,INF));
    for(int i = 0;i < M;i++){
        int a,b;long long c;
        std::cin >> a >> b >> c;
        G[a][b] = std::min(G[a][b],c);
    }
    warshall_floyd<long long> WF(G,INF);
    if(WF.negative_cycle()){
        std::cout << "NEGATIVE CYCLE\n";
    }
    else{
        auto ans = WF.get_dist();
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                std::cout << (ans[i][j] == INF ? "INF" : std::to_string(ans[i][j])) << (j == N - 1 ? "\n" : " ");
            }
        }
    }
}