#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#include <vector>

#include "../data-structure/disjoint_sparse_table.hpp"

long long op(long long a,long long b){return a + b;}

int main(){
    int N,Q;
    std::cin >> N >> Q;
    std::vector<long long> vec(N);
    for(int i = 0;i < N;i++)std::cin >> vec[i];
    DisjointSparseTable<long long,op> dst(vec);
    for(int i = 0;i < Q;i++){
        int l,r;
        std::cin >> l >> r;
        std::cout << dst.query(l,r) << "\n";
    }
}