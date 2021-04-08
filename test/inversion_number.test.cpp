#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

#include <iostream>
#include <vector>

#include "../algorithm/inversion_number.hpp"

int main(){
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    for(int i = 0;i < N;i++)std::cin >> vec[i];
    std::cout << inversion_number(vec) << "\n";
}