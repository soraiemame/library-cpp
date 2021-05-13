#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include <vector>
#include <iostream>

#include "../graph/topological_sort.hpp"

int main(){
    int N,M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> G(N);
    for(int i = 0;i < M;i++){
        int a,b;
        std::cin >> a >> b;
        G[a].push_back(b);
    }
    auto ans = topological_sort(G);
    for(int v : ans){
        std::cout << v << "\n";
    }
}