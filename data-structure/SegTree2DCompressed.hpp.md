---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SegTree2DCompressed.test.cpp
    title: test/SegTree2DCompressed.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/SegTree2DCompressed.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n\n#include <atcoder/segtree.hpp>\n\
    \ntemplate <class S, S(*op)(S, S), S(*e)()> struct SegTree2DCompress {\npublic:\n\
    \    using coordinate_t = long long;\n\n    SegTree2DCompress() : SegTree2DCompress(std::vector<coordinate_t>(),\
    \ std::vector<coordinate_t>()) {}\n    explicit SegTree2DCompress(const std::vector<coordinate_t>&\
    \ px, const std::vector<coordinate_t>& py) {\n        for (coordinate_t x : px)hidx.emplace_back(x);\n\
    \        compress(hidx);\n        h = 1;\n        while (h < int(hidx.size()))h\
    \ <<= 1;\n        widx.resize(h * 2);\n        int sz = int(px.size());\n    \
    \    for (int i = 0; i < sz;i++) {\n            int ix = std::lower_bound(hidx.begin(),\
    \ hidx.end(), px[i]) - hidx.begin();\n            widx[ix + h].emplace_back(py[i]);\n\
    \        }\n        for (int i = h * 2 - 1;i >= 1;i--) {\n            compress(widx[i]);\n\
    \            for (coordinate_t p : widx[i])widx[i / 2].emplace_back(p);\n    \
    \    }\n        data.resize(h * 2);\n        for (int i = 1; i < h * 2; i++)data[i]\
    \ = atcoder::segtree<S, op, e>(wsz(i));\n    }\n\n    void set(coordinate_t x,\
    \ coordinate_t y, S v) {\n        int ix = std::lower_bound(hidx.begin(), hidx.end(),\
    \ x) - hidx.begin();\n        assert(ix < h);\n        ix += h;\n        int iy\
    \ = std::lower_bound(widx[ix].begin(), widx[ix].end(), y) - widx[ix].begin();\n\
    \        data[ix].set(iy, v);\n        int seen = -1, idx = -1;\n        ix >>=\
    \ 1;\n        for (; ix > 0; ix >>= 1) {\n            iy = std::lower_bound(widx[ix].begin(),\
    \ widx[ix].end(), y) - widx[ix].begin();\n            assert(iy < wsz(ix));\n\
    \            assert(widx[ix][iy] == y);\n            int liy = seen == ix * 2\
    \ ? idx : std::lower_bound(widx[ix * 2].begin(), widx[ix * 2].end(), y) - widx[ix\
    \ * 2].begin();\n            int riy = seen == ix * 2 + 1 ? idx : std::lower_bound(widx[ix\
    \ * 2 + 1].begin(), widx[ix * 2 + 1].end(), y) - widx[ix * 2 + 1].begin();\n \
    \           S vl = e(), vr = e();\n            if (liy < wsz(ix * 2) && widx[ix\
    \ * 2][liy] == y)vl = data[ix * 2].get(liy);\n            if (riy < wsz(ix * 2\
    \ + 1) && widx[ix * 2 + 1][riy] == y)vr = data[ix * 2 + 1].get(riy);\n       \
    \     data[ix].set(iy, op(vl, vr));\n            seen = ix; idx = iy;\n      \
    \  }\n    }\n\n    S prod(coordinate_t lx, coordinate_t ly, coordinate_t rx, coordinate_t\
    \ ry) const {\n        int lix = std::lower_bound(hidx.begin(), hidx.end(), lx)\
    \ - hidx.begin();\n        int rix = std::lower_bound(hidx.begin(), hidx.end(),\
    \ rx) - hidx.begin();\n        S sml = e(), smr = e();\n        lix += h; rix\
    \ += h;\n        while (lix < rix) {\n            if (lix & 1) {\n           \
    \     int liy = std::lower_bound(widx[lix].begin(), widx[lix].end(), ly) - widx[lix].begin();\n\
    \                int riy = std::lower_bound(widx[lix].begin(), widx[lix].end(),\
    \ ry) - widx[lix].begin();\n                sml = op(sml, data[lix].prod(liy,\
    \ riy));\n                lix++;\n            }\n            if (rix & 1) {\n\
    \                rix--;\n                int liy = std::lower_bound(widx[rix].begin(),\
    \ widx[rix].end(), ly) - widx[rix].begin();\n                int riy = std::lower_bound(widx[rix].begin(),\
    \ widx[rix].end(), ry) - widx[rix].begin();\n                smr = op(smr, data[rix].prod(liy,\
    \ riy));\n            }\n            lix >>= 1;\n            rix >>= 1;\n    \
    \    }\n        return op(sml, smr);\n    }\n\n    S get(coordinate_t x, coordinate_t\
    \ y) const {\n        int ix = std::lower_bound(hidx.begin(), hidx.end(), x) -\
    \ hidx.begin();\n        int iy = std::lower_bound(widx[ix + h].begin(), widx[ix\
    \ + h].end(), y) - widx[ix + h].begin();\n        return data[ix + h].get(iy);\n\
    \    }\n\n    template<class stream>\n    friend stream& operator<<(stream& os,\
    \ const SegTree2DCompress& st) {\n        os << \"\\n\";\n        for (int i =\
    \ 1;i < 2 * st.h;i++) {\n            os << \"[\";\n            for (int j = 0;j\
    \ < st.wsz(i);j++)os << st.data[i].get(j) << (j == int(st.widx[i].size()) - 1\
    \ ? \"\" : \",\");\n            os << \"]\\n\";\n        }\n        return os;\n\
    \    }\n\nprivate:\n    int h;\n    std::vector<atcoder::segtree<S, op, e>> data;\n\
    \    std::vector<std::vector<coordinate_t>> widx;\n    std::vector<coordinate_t>\
    \ hidx;\n\n    inline constexpr int wsz(int k) const noexcept { return int(widx[k].size());\
    \ }\n    static inline constexpr void compress(std::vector<coordinate_t>& v) {\
    \ std::sort(v.begin(), v.end()); v.erase(std::unique(v.begin(), v.end()), v.end());\
    \ }\n};\n\n\n"
  code: "#ifndef SORAIE_SEGTREE2D_COMPRESSED\n#define SORAIE_SEGTREE2D_COMPRESSED\n\
    \n#include <vector>\n#include <algorithm>\n#include <cassert>\n\n#include <atcoder/segtree.hpp>\n\
    \ntemplate <class S, S(*op)(S, S), S(*e)()> struct SegTree2DCompress {\npublic:\n\
    \    using coordinate_t = long long;\n\n    SegTree2DCompress() : SegTree2DCompress(std::vector<coordinate_t>(),\
    \ std::vector<coordinate_t>()) {}\n    explicit SegTree2DCompress(const std::vector<coordinate_t>&\
    \ px, const std::vector<coordinate_t>& py) {\n        for (coordinate_t x : px)hidx.emplace_back(x);\n\
    \        compress(hidx);\n        h = 1;\n        while (h < int(hidx.size()))h\
    \ <<= 1;\n        widx.resize(h * 2);\n        int sz = int(px.size());\n    \
    \    for (int i = 0; i < sz;i++) {\n            int ix = std::lower_bound(hidx.begin(),\
    \ hidx.end(), px[i]) - hidx.begin();\n            widx[ix + h].emplace_back(py[i]);\n\
    \        }\n        for (int i = h * 2 - 1;i >= 1;i--) {\n            compress(widx[i]);\n\
    \            for (coordinate_t p : widx[i])widx[i / 2].emplace_back(p);\n    \
    \    }\n        data.resize(h * 2);\n        for (int i = 1; i < h * 2; i++)data[i]\
    \ = atcoder::segtree<S, op, e>(wsz(i));\n    }\n\n    void set(coordinate_t x,\
    \ coordinate_t y, S v) {\n        int ix = std::lower_bound(hidx.begin(), hidx.end(),\
    \ x) - hidx.begin();\n        assert(ix < h);\n        ix += h;\n        int iy\
    \ = std::lower_bound(widx[ix].begin(), widx[ix].end(), y) - widx[ix].begin();\n\
    \        data[ix].set(iy, v);\n        int seen = -1, idx = -1;\n        ix >>=\
    \ 1;\n        for (; ix > 0; ix >>= 1) {\n            iy = std::lower_bound(widx[ix].begin(),\
    \ widx[ix].end(), y) - widx[ix].begin();\n            assert(iy < wsz(ix));\n\
    \            assert(widx[ix][iy] == y);\n            int liy = seen == ix * 2\
    \ ? idx : std::lower_bound(widx[ix * 2].begin(), widx[ix * 2].end(), y) - widx[ix\
    \ * 2].begin();\n            int riy = seen == ix * 2 + 1 ? idx : std::lower_bound(widx[ix\
    \ * 2 + 1].begin(), widx[ix * 2 + 1].end(), y) - widx[ix * 2 + 1].begin();\n \
    \           S vl = e(), vr = e();\n            if (liy < wsz(ix * 2) && widx[ix\
    \ * 2][liy] == y)vl = data[ix * 2].get(liy);\n            if (riy < wsz(ix * 2\
    \ + 1) && widx[ix * 2 + 1][riy] == y)vr = data[ix * 2 + 1].get(riy);\n       \
    \     data[ix].set(iy, op(vl, vr));\n            seen = ix; idx = iy;\n      \
    \  }\n    }\n\n    S prod(coordinate_t lx, coordinate_t ly, coordinate_t rx, coordinate_t\
    \ ry) const {\n        int lix = std::lower_bound(hidx.begin(), hidx.end(), lx)\
    \ - hidx.begin();\n        int rix = std::lower_bound(hidx.begin(), hidx.end(),\
    \ rx) - hidx.begin();\n        S sml = e(), smr = e();\n        lix += h; rix\
    \ += h;\n        while (lix < rix) {\n            if (lix & 1) {\n           \
    \     int liy = std::lower_bound(widx[lix].begin(), widx[lix].end(), ly) - widx[lix].begin();\n\
    \                int riy = std::lower_bound(widx[lix].begin(), widx[lix].end(),\
    \ ry) - widx[lix].begin();\n                sml = op(sml, data[lix].prod(liy,\
    \ riy));\n                lix++;\n            }\n            if (rix & 1) {\n\
    \                rix--;\n                int liy = std::lower_bound(widx[rix].begin(),\
    \ widx[rix].end(), ly) - widx[rix].begin();\n                int riy = std::lower_bound(widx[rix].begin(),\
    \ widx[rix].end(), ry) - widx[rix].begin();\n                smr = op(smr, data[rix].prod(liy,\
    \ riy));\n            }\n            lix >>= 1;\n            rix >>= 1;\n    \
    \    }\n        return op(sml, smr);\n    }\n\n    S get(coordinate_t x, coordinate_t\
    \ y) const {\n        int ix = std::lower_bound(hidx.begin(), hidx.end(), x) -\
    \ hidx.begin();\n        int iy = std::lower_bound(widx[ix + h].begin(), widx[ix\
    \ + h].end(), y) - widx[ix + h].begin();\n        return data[ix + h].get(iy);\n\
    \    }\n\n    template<class stream>\n    friend stream& operator<<(stream& os,\
    \ const SegTree2DCompress& st) {\n        os << \"\\n\";\n        for (int i =\
    \ 1;i < 2 * st.h;i++) {\n            os << \"[\";\n            for (int j = 0;j\
    \ < st.wsz(i);j++)os << st.data[i].get(j) << (j == int(st.widx[i].size()) - 1\
    \ ? \"\" : \",\");\n            os << \"]\\n\";\n        }\n        return os;\n\
    \    }\n\nprivate:\n    int h;\n    std::vector<atcoder::segtree<S, op, e>> data;\n\
    \    std::vector<std::vector<coordinate_t>> widx;\n    std::vector<coordinate_t>\
    \ hidx;\n\n    inline constexpr int wsz(int k) const noexcept { return int(widx[k].size());\
    \ }\n    static inline constexpr void compress(std::vector<coordinate_t>& v) {\
    \ std::sort(v.begin(), v.end()); v.erase(std::unique(v.begin(), v.end()), v.end());\
    \ }\n};\n\n#endif /*SORAIE_SEGTREE2D_COMPRESSED*/"
  dependsOn:
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  isVerificationFile: false
  path: data-structure/SegTree2DCompressed.hpp
  requiredBy: []
  timestamp: '2021-12-20 14:53:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SegTree2DCompressed.test.cpp
documentation_of: data-structure/SegTree2DCompressed.hpp
layout: document
redirect_from:
- /library/data-structure/SegTree2DCompressed.hpp
- /library/data-structure/SegTree2DCompressed.hpp.html
title: data-structure/SegTree2DCompressed.hpp
---