// https://codeforces.com/contest/901/problem/C
// Bipartite Segments

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 3e5 + 5;
vector<int> g[N];

ll nc2(int x)
{
    return (x * 1ll * (x + 1)) / 2;
}

void dfs(vector<pii> &ivs, vector<int> &last, vector<int> &vis, int cur, int par)
{

    vis[cur] = 2;
    last[cur] = par;
    for (int e : g[cur])
    {
        if (e != par)
        {
            if (vis[e] == 2)
            {

                int l = e, r = e, node = cur;
                while (node != e)
                {
                    l = min(l, node);
                    r = max(r, node);
                    node = last[node];
                }
                ivs.pb({l, r});
            }
            else if (vis[e] == 0)
                dfs(ivs, last, vis, e, cur);
        }
    }
    vis[cur] = 1;
}

void solve()
{
    int n, m, q;
    cin >> n >> m;
    vector<int> last(n + 1), right(n + 1), vis(n + 1);
    vector<ll> pre(n + 1);
    vector<pii> ivs;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs(ivs, last, vis, i, 0);
    sort(ivs.begin(), ivs.end());
    int sz = (int)ivs.size();
    vector<int> suf(sz + 1);
    suf[sz] = n + 1;
    for (int i = sz - 1; i >= 0; i--)
        suf[i] = min(suf[i + 1], ivs[i].second);
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j < sz && ivs[j].first < i)
            j++;
        right[i] = suf[j] - 1;
    }
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + right[i] - i + 1;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        int low = l, high = r;
        ll res = pre[r] - pre[l - 1];
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (right[mid] > r)
                high = mid;
            else
                low = mid + 1;
        }
        if (right[low] > r)
            res -= (pre[r] - pre[low - 1] - nc2(r - low + 1));
        cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}