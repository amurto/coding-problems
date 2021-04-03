#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 150;
ll nxt[N];
vector<vector<int>> g(N);
ll f(ll n)
{
    n = n * n * n;
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

ll ff(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum * sum * sum;
}

ll s(ll n, ll k)
{
    ll last = 0;
    while (last != n && k > 0)
    {
        last = n;
        n = ff(n);
        k--;
    }
    return n;
}

ll solve()
{
    ll n, k;
    cin >> n >> k;
    cout << s(n, k) << "\n";
    k--;
    ll d = 0;
    while (n > 0)
    {
        d += n % 10;
        n /= 10;
    }
    ll sz = g[d].size();
    if (k < sz)
        d = g[d][k];
    else
    {
        k %= sz;
        if (nxt[g[d].back()] == g[d].back())
            d = g[d].back();
        else
            d = g[d][k];
    }

    return d * d * d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 1; i < N; i++)
        nxt[i] = f(i);
    for (ll i = 1; i < N; i++)
    {
        vector<bool> vis(N);
        ll cur = i;
        while (!vis[cur])
        {
            g[i].pb(cur);
            vis[cur] = true;
            cur = nxt[cur];
        }
    }
    cout << nxt[28] << "\n";
    for (int x : g[13])
        cout << x << " ";
    cout << "\n";
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}