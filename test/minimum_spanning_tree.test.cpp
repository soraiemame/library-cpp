#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include <iostream>
#include <vector>

#include "../algorithm/minimum_spanning_tree.hpp"

int main(){
    int N,M;
    std::cin >> N >> M;
    std::vector<edge<int>> vec(M);
    for(int i = 0;i < M;i++){
        int a,b,c;
        std::cin >> a >> b >> c;
        vec[i] = edge(a,b,c);
    }
    std::cout << minimum_spanning_tree(vec).first << "\n";
}