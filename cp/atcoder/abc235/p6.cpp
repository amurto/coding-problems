#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 998244353, B = 10;

constexpr int nttmod = 998'244'353;

template <std::uint32_t P>
struct ModInt32
{
public:
    using i32 = std::int32_t;
    using u32 = std::uint32_t;
    using i64 = std::int64_t;
    using u64 = std::uint64_t;
    using m32 = ModInt32;
    using internal_value_type = u32;

private:
    u32 v;
    static constexpr u32 get_r()
    {
        u32 iv = P;
        for (u32 i = 0; i != 4; ++i)
            iv *= 2U - P * iv;
        return -iv;
    }
    static constexpr u32 r = get_r(), r2 = -u64(P) % P;
    static_assert((P & 1) == 1);
    static_assert(-r * P == 1);
    static_assert(P < (1 << 30));
    static constexpr u32 pow_mod(u32 x, u64 y)
    {
        u32 res = 1;
        for (; y != 0; y >>= 1, x = u64(x) * x % P)
            if (y & 1)
                res = u64(res) * x % P;
        return res;
    }
    static constexpr u32 reduce(u64 x)
    {
        return (x + u64(u32(x) * r) * P) >> 32;
    }
    static constexpr u32 norm(u32 x) { return x - (P & -(x >= P)); }

public:
    static constexpr u32 get_pr()
    {
        u32 tmp[32] = {}, cnt = 0;
        const u64 phi = P - 1;
        u64 m = phi;
        for (u64 i = 2; i * i <= m; ++i)
            if (m % i == 0)
            {
                tmp[cnt++] = i;
                while (m % i == 0)
                    m /= i;
            }
        if (m != 1)
            tmp[cnt++] = m;
        for (u64 res = 2; res != P; ++res)
        {
            bool flag = true;
            for (u32 i = 0; i != cnt && flag; ++i)
                flag &= pow_mod(res, phi / tmp[i]) != 1;
            if (flag)
                return res;
        }
        return 0;
    }
    constexpr ModInt32() : v(0){};
    ~ModInt32() = default;
    constexpr ModInt32(u32 _v) : v(reduce(u64(_v) * r2)) {}
    constexpr ModInt32(i32 _v) : v(reduce(u64(_v % i64(P) + i64(P)) * r2)) {}
    constexpr ModInt32(u64 _v) : v(reduce((_v % P) * r2)) {}
    constexpr ModInt32(i64 _v) : v(reduce(u64(_v % i64(P) + i64(P)) * r2)) {}
    constexpr ModInt32(const m32 &rhs) : v(rhs.v) {}
    constexpr u32 get() const { return norm(reduce(v)); }
    explicit constexpr operator u32() const { return get(); }
    explicit constexpr operator i32() const { return i32(get()); }
    constexpr m32 &operator=(const m32 &rhs) { return v = rhs.v, *this; }
    constexpr m32 operator-() const
    {
        m32 res;
        return res.v = (P << 1 & -(v != 0)) - v, res;
    }
    constexpr m32 inv() const { return pow(P - 2); }
    constexpr m32 &operator+=(const m32 &rhs)
    {
        return v += rhs.v - (P << 1), v += P << 1 & -(v >> 31), *this;
    }
    constexpr m32 &operator-=(const m32 &rhs)
    {
        return v -= rhs.v, v += P << 1 & -(v >> 31), *this;
    }
    constexpr m32 &operator*=(const m32 &rhs)
    {
        return v = reduce(u64(v) * rhs.v), *this;
    }
    constexpr m32 &operator/=(const m32 &rhs)
    {
        return this->operator*=(rhs.inv());
    }
    constexpr friend m32 operator+(const m32 &lhs, const m32 &rhs)
    {
        return m32(lhs) += rhs;
    }
    constexpr friend m32 operator-(const m32 &lhs, const m32 &rhs)
    {
        return m32(lhs) -= rhs;
    }
    constexpr friend m32 operator*(const m32 &lhs, const m32 &rhs)
    {
        return m32(lhs) *= rhs;
    }
    constexpr friend m32 operator/(const m32 &lhs, const m32 &rhs)
    {
        return m32(lhs) /= rhs;
    }
    constexpr friend bool operator==(const m32 &lhs, const m32 &rhs)
    {
        return norm(lhs.v) == norm(rhs.v);
    }
    constexpr friend bool operator!=(const m32 &lhs, const m32 &rhs)
    {
        return norm(lhs.v) != norm(rhs.v);
    }
    friend std::istream &operator>>(std::istream &is, m32 &rhs)
    {
        return is >> rhs.v, rhs.v = reduce(u64(rhs.v) * r2), is;
    }
    friend std::ostream &operator<<(std::ostream &os, const m32 &rhs)
    {
        return os << rhs.get();
    }
    constexpr m32 pow(i64 y) const
    {
        // assumes P is a prime
        i64 rem = y % (P - 1);
        if (y > 0 && rem == 0)
            y = P - 1;
        else
            y = rem;
        m32 res(1), x(*this);
        for (; y != 0; y >>= 1, x *= x)
            if (y & 1)
                res *= x;
        return res;
    }
};

using mint = ModInt32<nttmod>;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

mint solve()
{
    string str;
    int m;
    cin >> str >> m;
    int req_mask = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        req_mask |= (1 << x);
    }
    int len = (int)str.length();
    vector<vector<mint>> ten(B, vector<mint>(len + 1));
    for (int i = 0; i < B; i++)
        ten[i][0] = i;
    for (int j = 0; j < B; j++)
        for (int i = 1; i <= len; i++)
            ten[j][i] = ten[j][i - 1] * mint(10);
    vector<vector<mint>> dp(2, vector<mint>(1 << B)), ways(2, vector<mint>(1 << B));
    for (int mask = 0; mask < (1 << B); mask++)
        if ((mask & req_mask) == req_mask)
            ways[0][mask] = ways[1][mask] = mint(1);
    for (int cur = len - 1; cur >= 0; cur--)
    {
        vector<vector<mint>> tdp(2, vector<mint>(1 << B)), tways(2, vector<mint>(1 << B));
        for (int mask = 0; mask < (1 << B); mask++)
        {
            for (int is_small = 0; is_small < 2; is_small++)
            {
                int is_started = (mask > 1);
                int lim = str[cur] - '0';
                if (is_small)
                    lim = 9;
                mint sum = 0, cur_ways = 0;
                for (int i = 0; i <= lim; i++)
                {
                    int tmp_is_small = is_small;
                    if (i < lim)
                        tmp_is_small = 1;
                    if (i == 0)
                    {
                        int nmask = mask | is_started;
                        cur_ways += ways[tmp_is_small][nmask];
                        sum += dp[tmp_is_small][nmask];
                    }
                    else
                    {
                        int nmask = mask | (1 << i);
                        cur_ways += ways[tmp_is_small][nmask];
                        sum += ten[i][len - cur - 1] * ways[tmp_is_small][nmask];
                        sum += dp[tmp_is_small][nmask];
                    }
                }
                tways[is_small][mask] = cur_ways;
                tdp[is_small][mask] = sum;
            }
        }
        swap(dp, tdp);
        swap(ways, tways);
    }
    return dp[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}