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

const int N = 1e6 + 5;
ll f(ll a, ll b)
{
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

ll solve()
{
    ll n, res = LLONG_MAX;
    cin >> n;
    for (ll i = 0; i < N; i++)
    {
        ll low = 0, high = N, val = N;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (f(i, mid) >= n)
            {
                val = min(val, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        ll v = f(i, val);
        if (v >= n)
            res = min(res, v);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}