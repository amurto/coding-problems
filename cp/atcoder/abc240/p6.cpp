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

const ll inf = LLONG_MAX;
ll nc2(ll v)
{
    return (v * (v + 1)) / 2;
}

ll solve()
{
    int n, m;
    cin >> n >> m;
    ll res = -inf;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    ll cur = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur >= 0 && x[i] < 0)
        {
            ll l = 1, r = y[i], mx = 1;
            while (l <= r)
            {
                ll mid = l + (r - l) / 2;
                if (cur + mid * x[i] >= 0)
                {
                    mx = max(mx, mid);
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            res = max(res, sum + (cur * mx) + (x[i] * nc2(mx)));
        }
        res = max(res, sum + cur + x[i]);
        res = max(res, sum + (cur * y[i]) + (x[i] * nc2(y[i])));
        sum += (cur * y[i]);
        sum += (x[i] * nc2(y[i]));
        cur += (x[i] * y[i]);
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