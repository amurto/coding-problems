#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, bn = 31;
vector<vector<int>> g(N), b(N, vector<int>(bn));
vector<int> a(N), st(N);
vector<ll> res(N);
void merge(vector<int> &b1, vector<int> &b2)
{
    for (int i = 0; i < bn; i++)
        b1[i] += b2[i];
}

int dfs(int cur, int last)
{
    int sz = 0;
    st[cur] = 1;
    for (int e : g[cur])
    {
        if (e == last)
            continue;
        sz += dfs(e, cur);
        merge(b[cur], b[e]);
    }
    for (int i = 0; i < bn; i++)
        if (1 & (a[cur] >> i))
            b[cur][i] = sz - b[cur][i];
    for (int i = 0; i < bn; i++)
        b[cur][i] += (1 & (a[cur] >> i));
    st[cur] += sz;
    return st[cur];
}

void f(vector<int> bs, int cur, int last, int n)
{
    ll sum = 0;
    int sz = n - st[cur];
    vector<int> t = bs;
    for (int i = 0; i < bn; i++)
    {
        if (1 & (a[cur] >> i))
            t[i] = sz - t[i];
        t[i] += b[cur][i];
        sum += t[i] * (1ll << i);
    }
    res[cur] = sum;
    for (int e : g[cur])
    {
        if (e != last)
        {
            vector<int> tmp = t;
            for (int i = 0; i < bn; i++)
            {
                if (1 & (a[cur] >> i))
                    tmp[i] -= (st[e] - b[e][i]);
                else
                    tmp[i] -= b[e][i];
            }
            f(tmp, e, cur, n);
        }
    }
}

void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st[i] = 0;
        for (int j = 0; j < bn; j++)
            b[i][j] = 0;
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    vector<int> t(bn);
    f(t, 1, -1, n);
    cout << res[1];
    for (int i = 2; i <= n; i++)
        cout << " " << res[i];
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}