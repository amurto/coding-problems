// https://codeforces.com/contest/1363/problem/E
// Tree Shuffling

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, inf = 1e9;
vector<int> g[N];
int a[N], b[N], c[N];

vector<int> dfs(ll &res, int cur, int last, int mn)
{
    a[cur] = min(mn, a[cur]);
    vector<int> seq(2);
    if (b[cur] != c[cur])
        seq[b[cur]]++;
    for (int e : g[cur])
    {
        if (e != last)
        {
            vector<int> ret = dfs(res, e, cur, a[cur]);
            seq[0] += ret[0];
            seq[1] += ret[1];
        }
    }
    int rem = min(seq[0], seq[1]);
    res += 2ll * rem * a[cur];
    seq[0] -= rem;
    seq[1] -= rem;
    return seq;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll res = 0;
    vector<int> seq = dfs(res, 1, 1, inf);
    max(seq[0], seq[1]) > 0 ? cout << "-1\n" : cout << res << "\n";
    return 0;
}