---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SegTree2D.test.cpp
    title: test/SegTree2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/SegTree2D.hpp\"\n\n\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate <class S, S(*op)(S, S), S(*e)()> struct SegTree2D\
    \ {\npublic:\n    SegTree2D() { init(std::vector<std::vector<S>>()); }\n    explicit\
    \ SegTree2D(int _h, int _w) { init(std::vector<std::vector<S>>(_h, std::vector<S>(_w,\
    \ e()))); }\n    explicit SegTree2D(const std::vector<std::vector<S>>& _data)\
    \ { init(_data); }\n\n    void set(int x, int y, S v) {\n        assert(0 <= x\
    \ && x < _h && 0 <= y && y < _w);\n        x += h; y += w;\n        data[x][y]\
    \ = v;\n        for (int nx = x; nx > 0; nx >>= 1)\n            for (int ny =\
    \ y; ny > 0; ny >>= 1)\n                update(nx, ny);\n    }\n\n    S get(int\
    \ x, int y) const {\n        assert(0 <= x && x < _h && 0 <= y && y < _w);\n \
    \       return data[x + h][y + w];\n    }\n\n    S prod(int lx, int ly, int rx,\
    \ int ry) const {\n        assert(0 <= lx && lx <= rx && rx <= _h && 0 <= ly &&\
    \ ly <= ry && ry <= _w);\n        S sml = e(), smr = e();\n        int nlx = lx\
    \ + h, nrx = rx + h;\n        while (nlx < nrx) {\n            if (nlx & 1) {\n\
    \                S sml2 = e(), smr2 = e();\n                int nly = ly + w,\
    \ nry = ry + w;\n                while (nly < nry) {\n                    if (nly\
    \ & 1) sml2 = op(sml2, data[nlx][nly++]);\n                    if (nry & 1) smr2\
    \ = op(smr2, data[nlx][--nry]);\n                    nly >>= 1;\n            \
    \        nry >>= 1;\n                }\n                nlx++;\n             \
    \   sml = op(sml, op(sml2, smr2));\n            }\n            if (nrx & 1) {\n\
    \                nrx--;\n                S sml2 = e(), smr2 = e();\n         \
    \       int nly = ly + w, nry = ry + w;\n                while (nly < nry) {\n\
    \                    if (nly & 1) sml2 = op(sml2, data[nrx][nly++]);\n       \
    \             if (nry & 1) smr2 = op(smr2, data[nrx][--nry]);\n              \
    \      nly >>= 1;\n                    nry >>= 1;\n                }\n       \
    \         smr = op(smr, op(sml2, smr2));\n            }\n            nlx >>= 1;\n\
    \            nrx >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n  \
    \  S all_prod() const { return data[1][1]; }\n\n    template<class stream>\n \
    \   friend stream& operator<<(stream& os, const SegTree2D& st) {\n        // to\
    \ debug\n        os << \"\\n\";\n        for (int i = 1;i < 2 * st.h;i++) {\n\
    \            os << \"[\";\n            for (int j = 1;j < 2 * st.w;j++)\n    \
    \            os << st.data[i][j] << (j == 2 * st.w - 1 ? \"]\\n\" : \",\");\n\
    \        }\n        return os;\n    }\n\nprivate:\n    int h, w, logh, logw, _h,\
    \ _w;\n    std::vector<std::vector<S>> data;\n    void update(int x, int y) {\n\
    \        if (x >= h && y >= w)return;\n        else if (y < w) data[x][y] = op(data[x][2\
    \ * y], data[x][2 * y + 1]);\n        else data[x][y] = op(data[2 * x][y], data[2\
    \ * x + 1][y]);\n    }\n\n    void init(const std::vector<std::vector<S>>& _data)\
    \ {\n        _h = int(_data.size()); _w = int(_data[0].size());\n        int xh\
    \ = 1, xw = 1;\n        while (xh < _h)xh <<= 1, logh++;\n        while (xw <\
    \ _w)xw <<= 1, logw++;\n        h = xh; w = xw;\n        data = std::vector<std::vector<S>>(2\
    \ * h, std::vector<S>(2 * w, e()));\n        for (int i = 0;i < _h;i++)\n    \
    \        for (int j = 0;j < _w;j++)\n                data[i + h][j + w] = _data[i][j];\n\
    \        for (int i = 2 * h - 1;i >= 0;i--)\n            for (int j = 2 * w -\
    \ 1;j >= 0;j--)\n                update(i, j);\n    }\n};\n\n\n"
  code: "#ifndef SORAIE_SEGTREE2D\n#define SORAIE_SEGTREE2D\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate <class S, S(*op)(S, S), S(*e)()> struct SegTree2D\
    \ {\npublic:\n    SegTree2D() { init(std::vector<std::vector<S>>()); }\n    explicit\
    \ SegTree2D(int _h, int _w) { init(std::vector<std::vector<S>>(_h, std::vector<S>(_w,\
    \ e()))); }\n    explicit SegTree2D(const std::vector<std::vector<S>>& _data)\
    \ { init(_data); }\n\n    void set(int x, int y, S v) {\n        assert(0 <= x\
    \ && x < _h && 0 <= y && y < _w);\n        x += h; y += w;\n        data[x][y]\
    \ = v;\n        for (int nx = x; nx > 0; nx >>= 1)\n            for (int ny =\
    \ y; ny > 0; ny >>= 1)\n                update(nx, ny);\n    }\n\n    S get(int\
    \ x, int y) const {\n        assert(0 <= x && x < _h && 0 <= y && y < _w);\n \
    \       return data[x + h][y + w];\n    }\n\n    S prod(int lx, int ly, int rx,\
    \ int ry) const {\n        assert(0 <= lx && lx <= rx && rx <= _h && 0 <= ly &&\
    \ ly <= ry && ry <= _w);\n        S sml = e(), smr = e();\n        int nlx = lx\
    \ + h, nrx = rx + h;\n        while (nlx < nrx) {\n            if (nlx & 1) {\n\
    \                S sml2 = e(), smr2 = e();\n                int nly = ly + w,\
    \ nry = ry + w;\n                while (nly < nry) {\n                    if (nly\
    \ & 1) sml2 = op(sml2, data[nlx][nly++]);\n                    if (nry & 1) smr2\
    \ = op(smr2, data[nlx][--nry]);\n                    nly >>= 1;\n            \
    \        nry >>= 1;\n                }\n                nlx++;\n             \
    \   sml = op(sml, op(sml2, smr2));\n            }\n            if (nrx & 1) {\n\
    \                nrx--;\n                S sml2 = e(), smr2 = e();\n         \
    \       int nly = ly + w, nry = ry + w;\n                while (nly < nry) {\n\
    \                    if (nly & 1) sml2 = op(sml2, data[nrx][nly++]);\n       \
    \             if (nry & 1) smr2 = op(smr2, data[nrx][--nry]);\n              \
    \      nly >>= 1;\n                    nry >>= 1;\n                }\n       \
    \         smr = op(smr, op(sml2, smr2));\n            }\n            nlx >>= 1;\n\
    \            nrx >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n  \
    \  S all_prod() const { return data[1][1]; }\n\n    template<class stream>\n \
    \   friend stream& operator<<(stream& os, const SegTree2D& st) {\n        // to\
    \ debug\n        os << \"\\n\";\n        for (int i = 1;i < 2 * st.h;i++) {\n\
    \            os << \"[\";\n            for (int j = 1;j < 2 * st.w;j++)\n    \
    \            os << st.data[i][j] << (j == 2 * st.w - 1 ? \"]\\n\" : \",\");\n\
    \        }\n        return os;\n    }\n\nprivate:\n    int h, w, logh, logw, _h,\
    \ _w;\n    std::vector<std::vector<S>> data;\n    void update(int x, int y) {\n\
    \        if (x >= h && y >= w)return;\n        else if (y < w) data[x][y] = op(data[x][2\
    \ * y], data[x][2 * y + 1]);\n        else data[x][y] = op(data[2 * x][y], data[2\
    \ * x + 1][y]);\n    }\n\n    void init(const std::vector<std::vector<S>>& _data)\
    \ {\n        _h = int(_data.size()); _w = int(_data[0].size());\n        int xh\
    \ = 1, xw = 1;\n        while (xh < _h)xh <<= 1, logh++;\n        while (xw <\
    \ _w)xw <<= 1, logw++;\n        h = xh; w = xw;\n        data = std::vector<std::vector<S>>(2\
    \ * h, std::vector<S>(2 * w, e()));\n        for (int i = 0;i < _h;i++)\n    \
    \        for (int j = 0;j < _w;j++)\n                data[i + h][j + w] = _data[i][j];\n\
    \        for (int i = 2 * h - 1;i >= 0;i--)\n            for (int j = 2 * w -\
    \ 1;j >= 0;j--)\n                update(i, j);\n    }\n};\n\n#endif /*SORAIE_SEGTREE2D*/\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/SegTree2D.hpp
  requiredBy: []
  timestamp: '2021-12-20 10:11:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SegTree2D.test.cpp
documentation_of: data-structure/SegTree2D.hpp
layout: document
redirect_from:
- /library/data-structure/SegTree2D.hpp
- /library/data-structure/SegTree2D.hpp.html
title: data-structure/SegTree2D.hpp
---
