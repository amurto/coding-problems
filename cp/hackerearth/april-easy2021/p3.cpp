#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 150;
ll nxt[N], last[N];
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

ll recur(ll n, ll k)
{
    int sz = g[n].size();
    if (k > sz)
        return (last[n] == n) ? g[n][(k - 1) % sz] : recur(last[n], k - sz + (g[n].back() == last[n]));
    return g[n][k - 1];
}

ll solve()
{
    ll n, k, d = 0;
    cin >> n >> k;
    while (n > 0)
    {
        d += n % 10;
        n /= 10;
    }
    d = recur(d, k);
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
        last[i] = cur;
    }
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}