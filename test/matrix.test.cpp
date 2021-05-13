#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <iostream>
#include <vector>

#include "../math/matrix.hpp"
#include "../math/modint.hpp"

int main(){
    using mint = modint998244353;
    using mat = Matrix<mint>;
    
    int N,M,K;
    std::cin >> N >> M >> K;
    
    mat A(N,M),B(M,K);
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++)std::cin >> A[i][j];
    }
    for(int i = 0;i < M;i++){
        for(int j = 0;j < K;j++)std::cin >> B[i][j];
    }

    mat ans = A * B;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < K;j++){
            std::cout << ans[i][j] << (j == K - 1 ? "\n" : " ");
        }
    }
}