#ifndef SORAIE_RANDBASE
#define SORAIE_RANDBASE

#include <cassert>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unordered_set>

namespace my_rand{
    // [0, 2^64 - 1)
    uint64_t rng(){
        static uint64_t x_ =
            uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(
                        std::chrono::high_resolution_clock::now().time_since_epoch())
                        .count()) *
            10150724397891781847ULL;
        x_ ^= x_ << 7;
        return x_ ^= x_ >> 9;
    }

    // [l, r)
    int64_t randint(int64_t l,int64_t r) {
        assert(l < r);
        return l + rng() % (r - l);
    }

    // [0.0, 1.0)
    double rnd(){
        union raw_cast{
            double t;
            uint64_t u;
        };
        constexpr uint64_t p = uint64_t(1023 - 64) << 52;
        return rng() * ((raw_cast*)(&p))->t;
    }

    uint64_t rng128(){
        static uint64_t tx = 123456789,ty = 362436069,tz = 521288629,tw = 88675123;
        uint64_t tt = (tx^(tx<<11));
        tx = ty; ty = tz; tz = tw;
        return (tw=(tw^(tw>>19))^(tt^(tt>>8)));
    }

    int64_t xor128(int64_t l,int64_t r){
        assert(l < r);
        return l + rng128() % (r - l);
    }
}

using my_rand::randint;
using my_rand::rnd;
using my_rand::rng;
using my_rand::xor128;
using my_rand::rng128;

#endif /*SORAIE_RANDBASE*/