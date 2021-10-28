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

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<ll> arr(n + 2), pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n + 1; i++)
        pre[i] = __gcd(pre[i - 1], arr[i]);
    for (int i = n; i >= 0; i--)
        suf[i] = __gcd(suf[i + 1], arr[i]);
    for (int i = 1; i <= n; i++)
    {
        if (pre[i - 1] != pre[i])
        {
            ll p = pre[i - 1], mid = 0;
            for (int j = i + 1; j <= n; j++)
            {
                ll cur = __gcd(p, suf[j + 1]);
                ll tmp = __gcd(cur, arr[i]);
                cur /= tmp;
                res = max(res, tmp * __gcd(cur, arr[j]));
                p = __gcd(p, arr[j]);
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