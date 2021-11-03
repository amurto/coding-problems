#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class fraction
{
public:
    ll p = 0, q = 1;
    fraction() {}
    fraction(ll p, ll q) : p(p), q(q) {}
    void reduce()
    {
        ll g = __gcd(p, q);
        p /= g;
        q /= g;
    }
    bool operator<(const fraction &other) const
    {
        return p * other.q < other.p * q;
    }
    bool operator<=(const fraction &other) const
    {
        return p * other.q <= other.p * q;
    }
    bool operator==(const fraction &other) const
    {
        return p * other.q == other.p * q;
    }
    bool operator>(const fraction &other) const
    {
        return p * other.q > other.p * q;
    }
    bool operator>=(const fraction &other) const
    {
        return p * other.q >= other.p * q;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fraction f = fraction(1, 1);
    return 0;
}