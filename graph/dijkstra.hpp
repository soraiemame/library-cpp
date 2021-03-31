#ifndef SORAIE_DIJKSTRA
#define SORAIE_DIJKSTRA

#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>

#include "../utils/graph_alias.hpp"

namespace dijkstra{
    int _s = -1;
    std::vector<int> from;

    template<class T>
    std::vector<T> get_dist(const std::vector<std::vector<edge<T>>>& G,const std::vector<int>& st,T LM = std::numeric_limits<T>::max()){
        from.resize(G.size(),-1);
        std::vector<T> res(G.size(),LM);
        std::priority_queue<std::pair<T,int>,std::vector<std::pair<T,int>>,std::greater<std::pair<T,int>>> que;
        for(const int &a : st){
            que.push(std::make_pair(0,a));
            res[a] = 0;
        }
        while(!que.empty()){
            auto p = que.top();
            que.pop();
            if(res[p.second] < p.first)continue;
            for(const edge<T> &e : G[p.second]){
                if(res[e.to] > res[p.second] + e.cost){
                    res[e.to] = res[p.second] + e.cost;
                    from[e.to] = p.second;
                    que.push(std::make_pair(res[e.to],e.to));
                }
            }
        }
        return res;
    }

    template<class V,class E,long long (*trans)(E,long long)>
    std::vector<V> get_dist(const std::vector<std::vector<E>>& G,const std::vector<int>& st,V LM = std::numeric_limits<V>::max()){
        std::vector<V> res(G.size(),LM);
        from.resize(G.size(),-1);
        std::priority_queue<std::pair<V,int>,std::vector<std::pair<V,int>>,std::greater<std::pair<V,int>>> que;
        for(const int& a : st){
            que.push(std::make_pair(0,a));
            res[a] = 0;
        }
        while(!que.empty()){
            auto p = que.top();
            que.pop();
            if(p.first > res[p.second])continue;
            for(auto e : G[p.second]){
                V nx = trans(e,p.first);
                if(nx < res[e.to]){
                    res[e.to] = nx;
                    from[e.to] = p.second;
                    que.push(std::make_pair(res[e.to],e.to));
                }
            }
        }
        return res;
    }

    template<class T>
    std::vector<T> get_dist(const std::vector<std::vector<edge<T>>>& G,int s,T LM = std::numeric_limits<T>::max()){
        _s = s;
        std::vector<int> st = {s};
        return get_dist(G,st,LM);
    }
    template<class V,class E,long long (*trans)(E,long long)>
    std::vector<V> get_dist(const std::vector<std::vector<E>>& G,int s,V LM = std::numeric_limits<V>::max()){
        _s = s;
        std::vector<int> st = {s};
        return get_dist<V,E,trans>(G,st,LM);
    }

    std::vector<int> path(int s,int t){
        if(s == t)return {s};
        else if(from[t] == -1)return {};
        std::vector<int> res;
        for(int cur = t;cur != s;cur = from[cur])res.push_back(cur);
        res.push_back(s);
        std::reverse(res.begin(),res.end());
        return res;
    }

    std::vector<int> path(int t){
        assert(_s != -1);
        return path(_s,t);
    }
};
using dijkstra::get_dist;
using dijkstra::path;

#endif /*SORAIE_DIJKSTRA*/