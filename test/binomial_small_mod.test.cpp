#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"

#include <iostream>

#include "../math/binomial_small_mod.hpp"

int main(){
    int T,M;
    std::cin >> T >> M;
    binomial bin(M);
    while(T--){
        long long n,k;
        std::cin >> n >> k;
        std::cout << bin.C(n,k) << "\n";
    }
}
