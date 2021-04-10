#ifndef SORAIE_DYNAMIC_MODINT
#define SORAIE_DYNAMIC_MODINT

#include <iostream>
#include <algorithm>

struct dynamic_modint{
    int x;
    dynamic_modint(long long a = 0):x((a % get_mod() + get_mod()) % get_mod()){}
    inline dynamic_modint operator-()const noexcept{return dynamic_modint(-x);}
    inline dynamic_modint &operator+=(const dynamic_modint &a)noexcept{
        if((x += a.x) >= get_mod())x -= get_mod();
        return *this;
    }
    inline dynamic_modint &operator-=(const dynamic_modint &a)noexcept{
        if((x -= a.x) < get_mod())x += get_mod();
        return *this;
    }
    inline dynamic_modint &operator*=(const dynamic_modint &a)noexcept{
        x = (long long)(x) * a.x % get_mod();
        return *this;
    }
    inline dynamic_modint &operator++()noexcept{
        x++;
        if(x == get_mod())x = 0;
        return *this;
    }
    inline dynamic_modint operator++(int)noexcept{
        dynamic_modint res(*this);
        operator++();
        return res;
    }
    inline dynamic_modint &operator--()noexcept{
        x--;
        if(x == -1)x = get_mod() - 1;
        return *this;
    }
    inline dynamic_modint operator--(int)noexcept{
        dynamic_modint res(*this);
        operator--();
        return res;
    }
    inline dynamic_modint operator+(const dynamic_modint &a)const noexcept{
        dynamic_modint res(*this);
        return res += a;
    }
    inline dynamic_modint operator-(const dynamic_modint &a)const noexcept{
        dynamic_modint res(*this);
        return res -= a;
    }
    inline dynamic_modint operator*(const dynamic_modint &a)const noexcept{
        dynamic_modint res(*this);
        return res *= a;
    }
    inline dynamic_modint inv()const{
        int a = x,b = get_mod(),u = 1,v = 0,t;
        while(b){
            t = a / b;
            a -= t * b;std::swap(a,b);
            u -= t * v;std::swap(u,v);
        }
        return u;
    }
    inline dynamic_modint &operator/=(const dynamic_modint &a)noexcept{return (*this) *= a.inv();}
    inline dynamic_modint operator/(const dynamic_modint &a)const noexcept{
        dynamic_modint res(*this);
        return res /= a;
    }
    inline constexpr bool operator==(const dynamic_modint &a)const noexcept{return x == a.x;}
    friend std::istream &operator>>(std::istream &is,dynamic_modint &a) {
        is >> a.x;
        a.x = (a.x % get_mod() + get_mod()) % get_mod();
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os,const dynamic_modint &a){
        os << a.x;
        return os;
    }
    dynamic_modint pow(long long b)const noexcept{
        dynamic_modint res(1),mul(x);
        while(b > 0){
            if(b & 1)res *= mul;
            mul *= mul;
            b >>= 1;
        }
        return res;
    }

    static int &get_mod(){
        static int dynamic_modint_mod = 0;
        return dynamic_modint_mod;
    }

    static void set_mod(int mod){get_mod() = mod;}
};

#endif /*SORAIE_DYNAMIC_MODINT*/