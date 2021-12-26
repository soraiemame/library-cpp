#ifndef SORAIE_PERSISTENT_UNIONFIND
#define SORAIE_PERSISTENT_UNIONFIND

#include <cassert>
#include <algorithm>

#include "persistent_array.hpp"

struct PersistentUnionFind {
    PersistentUnionFind(int n = 0) : n(n), dat(n) {
        for (int i = 0;i < n;i++)dat.set(i, -1);
    }

    int find(int a) const {
        assert(0 <= a && a < n);
        if (dat.get(a) < 0)return a;
        else return find(dat.get(a));
    }

    void merge(int a, int b) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        a = find(a);
        b = find(b);
        if (a == b)return;
        if (dat.get(a) > dat.get(b))std::swap(a, b);
        dat.set(a, dat.get(a) + dat.get(b));
        dat.set(b, a);
    }

    bool same(int a, int b) const {
        assert(0 <= a && a < n && 0 <= b && b < n);
        return find(a) == find(b);
    }

    int size(int a) const {
        assert(0 <= a && a < n);
        return -dat.get(find(a));
    }

    template<class stream> friend stream& operator<<(stream& os, const PersistentUnionFind& a) { return os << a.dat; }

    int n;
    PersistentArray<int> dat;
};

#endif /*SORAIE_PERSISTENT_UNIONFIND*/