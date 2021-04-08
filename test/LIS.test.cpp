#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D"

#include <iostream>
#include <vector>

#include "../algorithm/LIS_LDS.hpp"

int main(){
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    for(int i = 0;i < N;i++)std::cin >> vec[i];
    std::vector<int> ans = LIS(vec);
    std::cout << ans.size() << "\n";
}