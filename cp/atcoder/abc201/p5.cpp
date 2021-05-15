#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back

const int MOD = 1e9 + 7, N = 2e5 + 5, K = 60;
vector<pii> g[N];
int sub[N];

ll add(ll x, ll y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll mul(ll x, ll y)
{
    x %= MOD;
    return (x * y) % MOD;
}

int subtree_sum(int cur, int last)
{
    sub[cur] = 1;
    for (pii e : g[cur])
        if (e.first != last)
            sub[cur] += subtree_sum(e.first, cur);
    return sub[cur];
}

void merge(vector<int> &b1, vector<int> &b2)
{
    for (int i = 0; i < K; i++)
        b1[i] += b2[i];
}

vector<int> precompute(vector<vector<int>> &b, int cur, int last)
{
    for (pii e : g[cur])
    {
        if (e.first != last)
        {
            vector<int> tmp = precompute(b, e.first, cur);
            int sz = sub[e.first] - 1;
            for (ll i = 0; i < K; i++)
            {
                if ((e.second >> i) & 1)
                    tmp[i] = sz - tmp[i] + 1;
                b[cur][i] += tmp[i];
            }
        }
    }
    return b[cur];
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

ll dfs(vector<vector<int>> &b, int cur, int last, int n, vector<int> par)
{
    ll res = 0;
    for (int i = 0; i < K; i++)
    {
        if (par[i] + b[cur][i] > 0)
        {
            res = add(res, mul(1ll << i, par[i] + b[cur][i]));
            res %= MOD;
        }
    }
    merge(par, b[cur]);
    for (pii e : g[cur])
    {
        if (e.first != last)
        {
            vector<int> tmp = par, ctmp = b[e.first];
            int sz = sub[e.first] - 1;
            for (ll i = 0; i < K; i++)
                if ((e.second >> i) & 1)
                    ctmp[i] = sz - ctmp[i] + 1;
            for (int i = 0; i < K; i++)
                tmp[i] -= ctmp[i];
            sz = n - sub[e.first] - 1;
            for (ll i = 0; i < K; i++)
                if ((e.second >> i) & 1)
                    tmp[i] = sz - tmp[i] + 1;
            res = add(res, dfs(b, e.first, cur, n, tmp));
        }
    }
    return res;
}

ll solve()
{
    int n, u, v;
    ll w;
    cin >> n;
    vector<vector<int>> b(n + 1, vector<int>(K));
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    subtree_sum(1, 1);
    precompute(b, 1, 1);
    vector<int> par(K);
    return mul(dfs(b, 1, 1, n, par), 500000004);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}