#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#include <vector>

#include "../algorithm/RSQ.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    std::vector<long long> vec(N);
    for(int i = 0;i < N;i++)std::cin >> vec[i];
    RangeSumQuery<long long> rsq(vec);

    for(int i = 0;i < Q;i++){
        int l,r;
        std::cin >> l >> r;
        std::cout << rsq.query(l,r) << "\n";
    }
}