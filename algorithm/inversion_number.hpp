#ifndef SORAIE_INVERSION_NUMBER
#define SORAIE_INVERSION_NUMBER

#include <vector>
#include <algorithm>

#include "../atcoder/fenwicktree.hpp"

template<class T>
long long inversion_number(const std::vector<T> &V,bool compress = true){
    int n = V.size();
    std::vector<T> vec = V;
    if(compress){
        std::vector<T> zaatu = V;
        std::sort(zaatu.begin(),zaatu.end());
        for(T& a : vec)a = std::lower_bound(zaatu.begin(),zaatu.end(),a) - zaatu.begin();
    }
    atcoder::fenwick_tree<int> BIT(n);
    long long ans = 0;
    for(int i = 0;i < n;i++){
        ans = ans + i - BIT.sum(0,vec[i] + 1);
        BIT.add(vec[i],1);
    }
    return ans;
}

template<class T>
long long inversion_number(const std::vector<T>& a,const std::vector<T>& b) {
    assert(a.size() == b.size());
    auto za = b;
    auto ca = a,cb = b,sa = a,sb = b;
    std::sort(sa.begin(),sa.end());
    std::sort(sb.begin(),sb.end());
    if(sa != sb)return -1;
    std::sort(za.begin(),za.end());
    for(T& x : ca)x = std::lower_bound(za.begin(),za.end(),x) - za.begin();
    for(T& x : cb)x = std::lower_bound(za.begin(),za.end(),x) - za.begin();
    int sz = za.size();
    std::vector<std::vector<int>> ia(sz),ib(sz);
    for(int i = 0;i < sz;i++)ia[ca[i]].push_back(i);
    for(int i = 0;i < sz;i++)ib[cb[i]].push_back(i);
    for(int i = 0;i < sz;i++){
        for(int j = 0;j < int(ia[i].size());j++){
            ca[ia[i][j]] = ib[i][j];
        }
    }
    return inversion_number(ca,false);
}

#endif /*SORAIE_INVERSION_NUMBER*/