#ifndef SORAIE_WARSHALL_FLOYD
#define SORAIE_WARSHALL_FLOYD

#include <vector>

template<class T>
struct warshall_floyd{
    warshall_floyd(const std::vector<std::vector<T>>& G,T LM = std::numeric_limits<T>::max()):LM(LM){init(G);}

    void append(int from,int to,T cost){
        if(dist[from][to] <= cost)return;
        int n = dist.size();
        dist[from][to] = cost;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(dist[i][from] == LM || dist[to][j] == LM)continue;
                else if(dist[i][j] > dist[i][from] + cost + dist[to][j]){
                    dist[i][j] = dist[i][from] + cost + dist[to][j];
                    pre[i][j] = pre[to][j];
                }
            }
        }
    }
    
    std::vector<std::vector<T>> get_dist(){return dist;}

    std::vector<int> path(int s,int t){
        std::vector<int> res;
        for(int cur = t;cur != s;cur = pre[s][cur])res.push_back(cur);
        res.push_back(s);
        reverse(res.begin(),res.end());
        return res;
    }

    bool negative_cycle(){
        for(int i = 0;i < int(dist.size());i++)if(dist[i][i] < 0)return true;
        return false;
    }

private:
    void init(const std::vector<std::vector<T>>& G){
        dist = G;
        int n = G.size();
        for(int i = 0;i < n;i++)dist[i][i] = 0;
        pre = std::vector<std::vector<int>>(n,std::vector<int>(n,-1));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                for(int k = 0;k < n;k++){
                    if(dist[j][i] == LM || dist[i][k] == LM)continue;
                    else if(dist[j][k] > dist[j][i] + dist[i][k]){
                        dist[j][k] = dist[j][i] + dist[i][k];
                        pre[j][k] = pre[i][k];
                    }
                }
            }
        }
    }
    T LM;
    std::vector<std::vector<T>> dist;
    std::vector<std::vector<int>> pre;
};

#endif /*SORAIE_WARSHALL_FLOYD*/