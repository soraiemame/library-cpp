#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>

#include "../math/NTT_primitive_mod.hpp"

int main(){
    using ntt = NTT_primitive<998244353,31,23>;
    ntt n;
    using mint = ntt::mint;
    int N,M;
    std::cin >> N >> M;
    std::vector<mint> A(N),B(M);
    for(int i = 0;i < N;i++)std::cin >> A[i];
    for(int i = 0;i < M;i++)std::cin >> B[i];
    auto ans = n.convolution(A,B);
    for(int i = 0;i < N + M - 1;i++)std::cout << ans[i] << (i == N + M - 2 ? "\n" : " ");
}