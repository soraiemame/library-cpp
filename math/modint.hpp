#ifndef SORAIE_MODINT
#define SORAIE_MODINT

#include <algorithm>
#include <iostream>

template<int MOD = 1000000007>
struct modint{
    using mint = modint<MOD>;
    int x;
    modint(long long a = 0):x((a % MOD + MOD) % MOD){}
    inline constexpr modint operator-()const noexcept{return modint(-x);}
    inline constexpr modint &operator+=(const modint &a)noexcept{
        if((x += a.x) >= MOD)x -= MOD;
        return *this;
    }
    inline constexpr modint &operator-=(const modint &a)noexcept{
        if((x -= a.x) < 0)x += MOD;
        return *this;
    }
    inline constexpr modint &operator*=(const modint &a)noexcept{
        x = (long long)(x) * a.x % MOD;
        return *this;
    }
    inline constexpr modint &operator++()noexcept{
        x++;
        if(x == MOD)x = 0;
        return *this;
    }
    inline constexpr modint operator++(int)noexcept{
        modint res(*this);
        operator++();
        return res;
    }
    inline constexpr modint &operator--()noexcept{
        x--;
        if(x == -1)x = MOD - 1;
        return *this;
    }
    inline constexpr modint operator--(int)noexcept{
        modint res(*this);
        operator--();
        return res;
    }
    inline constexpr modint operator+(const modint &a)const noexcept{
        modint res(*this);
        return res += a;
    }
    inline constexpr modint operator-(const modint &a)const noexcept{
        modint res(*this);
        return res -= a;
    }
    inline constexpr modint operator*(const modint &a)const noexcept{
        modint res(*this);
        return res *= a;
    }
    inline constexpr modint inv()const{
        int a = x,b = MOD,u = 1,v = 0,t;
        while(b){
            t = a / b;
            a -= t * b;std::swap(a,b);
            u -= t * v;std::swap(u,v);
        }
        return u;
    }
    inline constexpr modint &operator/=(const modint &a)noexcept{return (*this) *= a.inv();}
    inline constexpr modint operator/(const modint &a)const noexcept{
        modint res(*this);
        return res /= a;
    }
    inline constexpr bool operator==(const modint &a)const noexcept{return x == a.x;}
    friend std::istream &operator>>(std::istream &is,modint &a) {
        is >> a.x;
        a.x = (a.x % MOD + MOD) % MOD;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os,const modint &a){
        os << a.x;
        return os;
    }
    inline constexpr mint pow(long long b)const noexcept{
        mint res(1),mul(x);
        while(b > 0){
            if(b & 1)res *= mul;
            mul *= mul;
            b >>= 1;
        }
        return res;
    }

    static constexpr int get_mod(){return MOD;}
};
using modint1000000007 = modint<1'000'000'007>;
using modint998244353 = modint<998'244'353>;

#endif /*SORAIE_MODINT*/