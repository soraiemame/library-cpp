#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <vector>

#include "../data-structure/persistent_unionfind.hpp"

int main(){
    int N,Q;
    std::cin >> N >> Q;
    std::vector<PersistentUnionFind> ufs(Q + 1,PersistentUnionFind(N));
    for(int i = 0;i < Q;i++){
        int t,k,u,v;
        std::cin >> t >> k >> u >> v;
        if(t == 0){
            ufs[i + 1] = ufs[k + 1];
            ufs[i + 1].merge(u,v);
        }
        else{
            std::cout << ufs[k + 1].same(u,v) << "\n";
        }
    }
}
