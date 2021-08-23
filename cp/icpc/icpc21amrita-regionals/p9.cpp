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
int parent[N], cap[N], r[N];

// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

void merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (rx == ry)
        return;
    // by size (capacity)
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
}

ll solve()
{
    int n, ones = 0;
    cin >> n;
    ll res = 2 * n;
    set<int> primes;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        if (r[i] == 1)
            ones++;
        int v = r[i];
        while (v > 1)
        {
            int p = lp[v];
            primes.insert(p);
            g[i].pb(p);
            while (v % p == 0)
                v /= p;
        }
    }
    if (n == 1)
        return 0;
    if (ones == n)
        return res;
    for (int p : primes)
    {
        parent[p] = p;
        cap[p] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!g[i].empty())
        {
            int sz = g[i].size();
            for (int j = 1; j < sz; j++)
                merge(g[i][0], g[i][j]);
        }
    }
    int min_prime = *primes.begin(), cnt = 0;
    for (int p : primes)
        if (root(p) == p)
            cnt++;
    if (ones == 0 && cnt == 1)
        return 0;
    if (min_prime == 2)
        res = min(res, 2ll * (cnt - 1 + ones));
    else
    {
        res = min(res, min(1ll * min_prime * (cnt - 1 + ones), 2ll * (cnt + ones)));
        if (ones > 0)
            res = min(res, 1ll * min_prime * (cnt - 1) + 2ll * (ones + 1));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}