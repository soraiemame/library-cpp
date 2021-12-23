---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/fastio.hpp\"\n\n\n\nnamespace fastio{\n    static\
    \ constexpr size_t buf_size = 1 << 18;\n    static constexpr size_t integer_size\
    \ = 20;\n    static constexpr size_t block_size = 10000;\n\n    static char inbuf[buf_size\
    \ + 1] = {};\n    static char outbuf[buf_size + 1] = {};\n    static char block_str[block_size\
    \ * 4 + 1] = {};\n\n    static constexpr uint64_t power10[] = {\n        1, 10,\
    \ 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,\n        1000000000,\
    \ 10000000000, 100000000000, 1000000000000, 10000000000000,\n        100000000000000,\
    \ 1000000000000000, 10000000000000000, 100000000000000000,\n        1000000000000000000,\
    \ 10000000000000000000u\n    };\n\n    struct Scanner {\n        private:\n  \
    \      size_t pos,end;\n\n        void load() {\n            end = fread(inbuf,1,buf_size,stdin);\n\
    \            inbuf[end] = '\\0';\n        }\n        void reload() {\n       \
    \     size_t len = end - pos;\n            memmove(inbuf,inbuf + pos,len);\n \
    \           end = len + fread(inbuf + len,1,buf_size - len,stdin);\n         \
    \   inbuf[end] = '\\0';\n            pos = 0;\n        }\n        void skip_space()\
    \ {\n            while(inbuf[pos] <= ' '){\n                if(__builtin_expect(++pos\
    \ == end, 0)) reload();\n            }\n        }\n        char get_next() { return\
    \ inbuf[pos++]; }\n        char get_next_nonspace() {\n            skip_space();\n\
    \            return inbuf[pos++];\n        }\n        public:\n        Scanner()\
    \ { load(); }\n\n        void scan(char& c) { c = get_next_nonspace(); }\n   \
    \     void scan(std::string& s){\n            skip_space();\n            s = \"\
    \";\n            do {\n                size_t start = pos;\n                while\
    \ (inbuf[pos] > ' ') pos++;\n                s += std::string(inbuf + start, inbuf\
    \ + pos);\n                if (inbuf[pos] !='\\0') break;\n                reload();\n\
    \            } while (true);\n        }\n\n        template <class T>\n      \
    \  typename std::enable_if<std::is_integral<T>::value, void>::type scan(T &x)\
    \ {\n            char c = get_next_nonspace();\n            if(__builtin_expect(pos\
    \ + integer_size >= end, 0)) reload();\n            bool neg = false;\n      \
    \      if (c == '-') neg = true, x = 0;\n            else x = c & 15;\n      \
    \      while ((c = get_next()) >= '0') x = x * 10 + (c & 15);\n            if\
    \ (neg) x = -x;\n        }\n\n        template <class Head, class... Others>\n\
    \        void scan(Head& head, Others&... others) {\n            scan(head); scan(others...);\n\
    \        }\n\n        template <class T>\n        Scanner& operator >> (T& x)\
    \ {\n            scan(x); return *this;\n        }\n    };\n\n    struct Printer\
    \ {\n        private:\n        size_t pos = 0;\n        \n        void flush()\
    \ {\n            fwrite(outbuf, 1, pos, stdout);\n            pos = 0;\n     \
    \   }\n\n        void pre_calc() {\n            for (size_t i = 0; i < block_size;\
    \ i++) {\n                size_t j = 4, k = i;\n                while (j--) {\n\
    \                    block_str[i * 4 + j] = k % 10 + '0';\n                  \
    \  k /= 10;\n                }\n            }\n        }\n\n        static constexpr\
    \ size_t get_integer_size(uint64_t n) {\n            if(n >= power10[10]) {\n\
    \                if (n >= power10[19]) return 20;\n                if (n >= power10[18])\
    \ return 19;\n                if (n >= power10[17]) return 18;\n             \
    \   if (n >= power10[16]) return 17;\n                if (n >= power10[15]) return\
    \ 16;\n                if (n >= power10[14]) return 15;\n                if (n\
    \ >= power10[13]) return 14;\n                if (n >= power10[12]) return 13;\n\
    \                if (n >= power10[11]) return 12;\n                return 11;\n\
    \            }\n            else {\n                if (n >= power10[9]) return\
    \ 10;\n                if (n >= power10[8]) return 9;\n                if (n >=\
    \ power10[7]) return 8;\n                if (n >= power10[6]) return 7;\n    \
    \            if (n >= power10[5]) return 6;\n                if (n >= power10[4])\
    \ return 5;\n                if (n >= power10[3]) return 4;\n                if\
    \ (n >= power10[2]) return 3;\n                if (n >= power10[1]) return 2;\n\
    \                return 1;\n            }\n        }\n\n        public:\n    \
    \    Printer() { pre_calc(); }\n        ~Printer() { flush(); }\n\n        void\
    \ print(char c){\n            outbuf[pos++] = c;\n            if (__builtin_expect(pos\
    \ == buf_size, 0)) flush();\n        }\n        void print(const char *s) {\n\
    \            while(*s != 0) {\n                outbuf[pos++] = *s++;\n       \
    \         // if (pos == buf_size) flush();\n                if (__builtin_expect(pos\
    \ == buf_size, 0)) flush();\n            }\n        }\n        void print(const\
    \ std::string& s) {\n            for(auto c : s){\n                outbuf[pos++]\
    \ = c;\n                // if (pos == buf_size) flush();\n                if (__builtin_expect(pos\
    \ == buf_size, 0)) flush();\n            }\n        }\n\n        template <class\
    \ T>\n        typename std::enable_if<std::is_integral<T>::value, void>::type\
    \ print(T x) {\n            if (__builtin_expect(pos + integer_size >= buf_size,\
    \ 0)) flush();\n            if (x < 0) print('-'), x = -x;\n            size_t\
    \ digit = get_integer_size(x);\n            size_t len = digit;\n            while\
    \ (len >= 4) {\n                len -= 4;\n                memcpy(outbuf + pos\
    \ + len, block_str + (x % block_size) * 4, 4);\n                x /= block_size;\n\
    \            }\n            memcpy(outbuf + pos, block_str + x * 4 + (4 - len),\
    \ len);\n            pos += digit;\n        }\n\n        template <class Head,\
    \ class... Others>\n        void print(const Head& head, const Others&... others){\n\
    \            print(head); print(' '); print(others...);\n        }\n\n       \
    \ template <class... Args>\n        void println(const Args&... args) {\n    \
    \        print(args...); print('\\n');\n        }\n        \n        template\
    \ <class T>\n        Printer& operator << (const T& x) {\n            print(x);\
    \ return *this;\n        }\n    };\n};\n\n#ifndef _SORAIE\nfastio::Scanner fin;\n\
    fastio::Printer fout;\n#define cin fin\n#define cout fout\n#endif\n\n\n"
  code: "#ifndef SORAIE_FASTIO\n#define SORAIE_FASTIO\n\nnamespace fastio{\n    static\
    \ constexpr size_t buf_size = 1 << 18;\n    static constexpr size_t integer_size\
    \ = 20;\n    static constexpr size_t block_size = 10000;\n\n    static char inbuf[buf_size\
    \ + 1] = {};\n    static char outbuf[buf_size + 1] = {};\n    static char block_str[block_size\
    \ * 4 + 1] = {};\n\n    static constexpr uint64_t power10[] = {\n        1, 10,\
    \ 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,\n        1000000000,\
    \ 10000000000, 100000000000, 1000000000000, 10000000000000,\n        100000000000000,\
    \ 1000000000000000, 10000000000000000, 100000000000000000,\n        1000000000000000000,\
    \ 10000000000000000000u\n    };\n\n    struct Scanner {\n        private:\n  \
    \      size_t pos,end;\n\n        void load() {\n            end = fread(inbuf,1,buf_size,stdin);\n\
    \            inbuf[end] = '\\0';\n        }\n        void reload() {\n       \
    \     size_t len = end - pos;\n            memmove(inbuf,inbuf + pos,len);\n \
    \           end = len + fread(inbuf + len,1,buf_size - len,stdin);\n         \
    \   inbuf[end] = '\\0';\n            pos = 0;\n        }\n        void skip_space()\
    \ {\n            while(inbuf[pos] <= ' '){\n                if(__builtin_expect(++pos\
    \ == end, 0)) reload();\n            }\n        }\n        char get_next() { return\
    \ inbuf[pos++]; }\n        char get_next_nonspace() {\n            skip_space();\n\
    \            return inbuf[pos++];\n        }\n        public:\n        Scanner()\
    \ { load(); }\n\n        void scan(char& c) { c = get_next_nonspace(); }\n   \
    \     void scan(std::string& s){\n            skip_space();\n            s = \"\
    \";\n            do {\n                size_t start = pos;\n                while\
    \ (inbuf[pos] > ' ') pos++;\n                s += std::string(inbuf + start, inbuf\
    \ + pos);\n                if (inbuf[pos] !='\\0') break;\n                reload();\n\
    \            } while (true);\n        }\n\n        template <class T>\n      \
    \  typename std::enable_if<std::is_integral<T>::value, void>::type scan(T &x)\
    \ {\n            char c = get_next_nonspace();\n            if(__builtin_expect(pos\
    \ + integer_size >= end, 0)) reload();\n            bool neg = false;\n      \
    \      if (c == '-') neg = true, x = 0;\n            else x = c & 15;\n      \
    \      while ((c = get_next()) >= '0') x = x * 10 + (c & 15);\n            if\
    \ (neg) x = -x;\n        }\n\n        template <class Head, class... Others>\n\
    \        void scan(Head& head, Others&... others) {\n            scan(head); scan(others...);\n\
    \        }\n\n        template <class T>\n        Scanner& operator >> (T& x)\
    \ {\n            scan(x); return *this;\n        }\n    };\n\n    struct Printer\
    \ {\n        private:\n        size_t pos = 0;\n        \n        void flush()\
    \ {\n            fwrite(outbuf, 1, pos, stdout);\n            pos = 0;\n     \
    \   }\n\n        void pre_calc() {\n            for (size_t i = 0; i < block_size;\
    \ i++) {\n                size_t j = 4, k = i;\n                while (j--) {\n\
    \                    block_str[i * 4 + j] = k % 10 + '0';\n                  \
    \  k /= 10;\n                }\n            }\n        }\n\n        static constexpr\
    \ size_t get_integer_size(uint64_t n) {\n            if(n >= power10[10]) {\n\
    \                if (n >= power10[19]) return 20;\n                if (n >= power10[18])\
    \ return 19;\n                if (n >= power10[17]) return 18;\n             \
    \   if (n >= power10[16]) return 17;\n                if (n >= power10[15]) return\
    \ 16;\n                if (n >= power10[14]) return 15;\n                if (n\
    \ >= power10[13]) return 14;\n                if (n >= power10[12]) return 13;\n\
    \                if (n >= power10[11]) return 12;\n                return 11;\n\
    \            }\n            else {\n                if (n >= power10[9]) return\
    \ 10;\n                if (n >= power10[8]) return 9;\n                if (n >=\
    \ power10[7]) return 8;\n                if (n >= power10[6]) return 7;\n    \
    \            if (n >= power10[5]) return 6;\n                if (n >= power10[4])\
    \ return 5;\n                if (n >= power10[3]) return 4;\n                if\
    \ (n >= power10[2]) return 3;\n                if (n >= power10[1]) return 2;\n\
    \                return 1;\n            }\n        }\n\n        public:\n    \
    \    Printer() { pre_calc(); }\n        ~Printer() { flush(); }\n\n        void\
    \ print(char c){\n            outbuf[pos++] = c;\n            if (__builtin_expect(pos\
    \ == buf_size, 0)) flush();\n        }\n        void print(const char *s) {\n\
    \            while(*s != 0) {\n                outbuf[pos++] = *s++;\n       \
    \         // if (pos == buf_size) flush();\n                if (__builtin_expect(pos\
    \ == buf_size, 0)) flush();\n            }\n        }\n        void print(const\
    \ std::string& s) {\n            for(auto c : s){\n                outbuf[pos++]\
    \ = c;\n                // if (pos == buf_size) flush();\n                if (__builtin_expect(pos\
    \ == buf_size, 0)) flush();\n            }\n        }\n\n        template <class\
    \ T>\n        typename std::enable_if<std::is_integral<T>::value, void>::type\
    \ print(T x) {\n            if (__builtin_expect(pos + integer_size >= buf_size,\
    \ 0)) flush();\n            if (x < 0) print('-'), x = -x;\n            size_t\
    \ digit = get_integer_size(x);\n            size_t len = digit;\n            while\
    \ (len >= 4) {\n                len -= 4;\n                memcpy(outbuf + pos\
    \ + len, block_str + (x % block_size) * 4, 4);\n                x /= block_size;\n\
    \            }\n            memcpy(outbuf + pos, block_str + x * 4 + (4 - len),\
    \ len);\n            pos += digit;\n        }\n\n        template <class Head,\
    \ class... Others>\n        void print(const Head& head, const Others&... others){\n\
    \            print(head); print(' '); print(others...);\n        }\n\n       \
    \ template <class... Args>\n        void println(const Args&... args) {\n    \
    \        print(args...); print('\\n');\n        }\n        \n        template\
    \ <class T>\n        Printer& operator << (const T& x) {\n            print(x);\
    \ return *this;\n        }\n    };\n};\n\n#ifndef _SORAIE\nfastio::Scanner fin;\n\
    fastio::Printer fout;\n#define cin fin\n#define cout fout\n#endif\n\n#endif /*SORAIE_FASTIO*/"
  dependsOn: []
  isVerificationFile: false
  path: utils/fastio.hpp
  requiredBy: []
  timestamp: '2021-12-20 10:21:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/fastio.hpp
layout: document
redirect_from:
- /library/utils/fastio.hpp
- /library/utils/fastio.hpp.html
title: utils/fastio.hpp
---
