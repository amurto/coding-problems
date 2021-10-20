// https://codeforces.com/contest/1500/problem/B
// Two chandeliers

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
    int n, m;
    ll k, res = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    if (n > m)
    {
        swap(n, m);
        swap(a, b);
    }
    vector<int> ids(2 * m + 1, -1), nodes;
    vector<ll> sum(m, n);
    for (int i = 0; i < n; i++)
        ids[a[i]] = i;
    for (int i = 0; i < m; i++)
        if (ids[b[i]] != -1)
            sum[(i - ids[b[i]] + m) % m]--;
    vector<bool> vis(m);
    int cur = 0;
    while (!vis[cur])
    {
        nodes.pb(cur);
        vis[cur] = true;
        cur += n;
        cur %= m;
    }
    int sz = (int)nodes.size();
    vector<ll> pre(sz);
    pre[0] = sum[0];
    for (int i = 1; i < sz; i++)
        pre[i] = pre[i - 1] + sum[nodes[i]];
    k--;
    res += ((1ll * sz * n) * (k / pre[sz - 1]));
    k %= pre[sz - 1];
    k++;
    for (int i = 0; i < sz; i++)
    {
        if (pre[i] >= k)
        {
            if (i - 1 >= 0)
                k -= pre[i - 1];
            for (int l = 0, r = nodes[i]; k > 0; l++, r = (r + 1) % m, res++)
                k -= (a[l] != b[r]);
            return res;
        }
        else
            res += n;
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