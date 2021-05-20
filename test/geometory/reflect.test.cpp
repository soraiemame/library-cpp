#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B"
#define ERROR 0.00000001

#include <iomanip>

#include "../../geometory/main.hpp"

int main(){
    std::cout << std::fixed << std::setprecision(15);
    point p1 = inputP(),p2 = inputP();
    int Q;
    std::cin >> Q;
    for(int i = 0;i < Q;i++){
        point q = inputP();
        auto ans = reflect(line(p1,p2),q);
        std::cout << ans.x << " " << ans.y << "\n";
    }
}