#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <iostream>
#include <vector>
#include <array>

#include "../data-structure/lichaotree.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    std::vector<long long> A(N),B(N),L(N),R(N);
    for(int i = 0;i < N;i++)std::cin >> L[i] >> R[i] >> A[i] >> B[i];
    std::vector<int> t(Q);
    std::vector<std::array<long long,4>> query(Q);
    std::vector<long long> xl;
    for(int i = 0;i < Q;i++){
        std::cin >> t[i];
        if(t[i] == 0){
            std::cin >> query[i][2] >> query[i][3] >> query[i][0] >> query[i][1];
        }
        else{
            std::cin >> query[i][0];
            xl.push_back(query[i][0]);
        }
    }
    LiChaoTree<long long> cht(xl);
    for(int i = 0;i < N;i++)cht.add_segment(A[i],B[i],L[i],R[i]);
    for(int i = 0;i < Q;i++){
        if(t[i] == 0)cht.add_segment(query[i][0],query[i][1],query[i][2],query[i][3]);
        else{
            long long ans = cht.get(query[i][0]);
            if(ans == 0)std::cout << "INFINITY\n";
            else std::cout << ans << "\n";
        }
    }
}