// https://codeforces.com/contest/1009/problem/F
// Dominant Indices

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;
vector<int> g[N];
int arr[N], sz[N], vis1[N], vis2[N], ver[N], dep[N], cnt[N], idx[N];

int set_sz(int cur, int last, int t, int d)
{
    dep[cur] = d;
    vis1[cur] = vis2[cur] = t;
    ver[t] = cur;
    sz[cur] = 1;
    for (int e : g[cur])
    {
        if (e != last)
        {
            vis2[cur] = max(vis2[cur], set_sz(e, cur, vis2[cur] + 1, d + 1));
            sz[cur] += sz[e];
        }
    }
    return vis2[cur];
}

void sack(int cur, int last, bool keep)
{
    int mx = -1, big = -1;
    for (int e : g[cur])
        if (e != last && sz[e] > mx)
            mx = sz[e], big = e;
    for (int e : g[cur])
        if (e != last && e != big)
            sack(e, cur, false);
    idx[cur] = dep[cur];
    int lvl = 1;
    if (big != -1)
    {
        sack(big, cur, true);
        idx[cur] = idx[big];
        lvl = cnt[idx[big]];
    }
    cnt[dep[cur]]++;
    if (cnt[dep[cur]] >= lvl)
    {
        idx[cur] = dep[cur];
        lvl = cnt[dep[cur]];
    }
    for (int e : g[cur])
    {
        if (e != last && e != big)
        {
            for (int i = vis1[e]; i <= vis2[e]; i++)
            {
                cnt[dep[ver[i]]]++;
                if (cnt[dep[ver[i]]] > lvl)
                {
                    idx[cur] = dep[ver[i]];
                    lvl = cnt[dep[ver[i]]];
                }
                else if (cnt[dep[ver[i]]] == lvl && dep[ver[i]] < idx[cur])
                    idx[cur] = dep[ver[i]];
            }
        }
    }
    if (!keep)
        for (int i = vis1[cur]; i <= vis2[cur]; i++)
            cnt[dep[ver[i]]]--;
}

void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        cnt[i] = 0;
    set_sz(1, 1, 0, 0);
    sack(1, 1, true);
    for (int i = 1; i <= n; i++)
        cout << idx[i] - dep[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}