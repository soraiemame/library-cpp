#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <iostream>
#include <vector>

#include "../data-structure/persistent_array.hpp"

int main(){
    int Q;
    std::cin >> Q;
    std::vector<PersistentArray<int>> qs(Q + 1,PersistentArray<int>(Q));
    std::vector<int> fr(Q + 1),ba(Q + 1);
    for(int i = 0;i < Q;i++){
        int q,t;
        std::cin >> q >> t;
        if(q == 0){
            int x;
            std::cin >> x;
            qs[i + 1] = qs[t + 1];
            fr[i + 1] = fr[t + 1];
            ba[i + 1] = ba[t + 1];
            qs[i + 1].set(ba[i + 1],x);
            ba[i + 1]++;
        }
        else{
            std::cout << qs[t + 1].get(fr[t + 1]) << "\n";
            qs[i + 1] = qs[t + 1];
            fr[i + 1] = fr[t + 1];
            ba[i + 1] = ba[t + 1];
            fr[i + 1]++;
        }
    }
}
