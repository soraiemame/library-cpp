#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <iostream>
#include <vector>

#include "../../graph/dijkstra.hpp"

int main(){
    int N,M,s,t;
    std::cin >> N >> M >> s >> t;
    std::vector<std::vector<edge<>>> G(N);
    for(int i = 0;i < M;i++){
        int a,b;long long c;
        std::cin >> a >> b >> c;
        G[a].push_back({b,c});
    }
    auto dist = get_dist(G,s);
    auto ans = path(t);
    if(ans.empty())std::cout << "-1\n";
    else{
        int sz = ans.size();
        std::cout << dist[t] << " " << sz - 1 << "\n";
        for(int i = 0;i < sz - 1;i++)std::cout << ans[i] << " " << ans[i + 1] << "\n";
    }
}