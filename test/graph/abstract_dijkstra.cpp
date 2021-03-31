#define PROBLEM "https://atcoder.jp/contests/abc192/tasks/abc192_e"

#include <iostream>
#include <vector>

#include "../../graph/dijkstra.hpp"

using V = long long;
struct E{int to;V cost,time;};
V trans(E e,V x){return (x + e.time - 1) / e.time * e.time + e.cost;}

int main(){
    int N,M,s,t;
    std::cin >> N >> M >> s >> t;
    s--;t--;
    std::vector<std::vector<V>> G(N);
    for(int i = 0;i < M;i++){
        int a,b;V c,d;
        std::cin >> a >> b >> c >> d;
        a--;b--;
        G[a].push_back({b,c,d});
        G[b].push_back({a,c,d});
    }
    const V INF = 1LL << 60;
    auto ans = get_dist<V,E,trans>(G,s,INF);
    std::cout << (ans[t] == INF ? -1 : ans[t]) << "\n";
}