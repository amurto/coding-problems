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

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    x %= MOD;
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

ll lcm(ll x, ll y)
{
    return x * y / __gcd(x, y);
}

int solve()
{
    ll b1, b2, diff_b, n_b, c1, c2, diff_c, n_c;
    cin >> b1 >> diff_b >> n_b >> c1 >> diff_c >> n_c;
    b2 = b1 + (n_b - 1) * diff_b, c2 = c1 + (n_c - 1) * diff_c;
    int res = 0;
    if (diff_c % diff_b > 0 || c1 < b1 || c2 > b2 || (c1 - b1) % diff_b > 0 || (b2 - c2) % diff_b > 0)
        return 0;
    for (ll num = 1; num * num <= diff_c; num++)
    {
        if (diff_c % num == 0)
        {
            // num
            if (lcm(num, diff_b) == diff_c)
            {
                ll t = diff_c / num;
                if (c1 - diff_c < b1)
                    return -1;
                if (c2 + diff_c > b2)
                    return -1;
                res = add(res, mul(t, t));
            }
            // dv
            ll dv = diff_c / num;
            if (dv != num && lcm(dv, diff_b) == diff_c)
            {
                ll t = diff_c / dv;
                if (c1 - diff_c < b1)
                    return -1;
                if (c2 + diff_c > b2)
                    return -1;
                res = add(res, mul(t, t));
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}