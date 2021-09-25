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

const int N = 8e5 + 5;
vector<int> g[N];
int F[N], cap[N], cur_cap[N], sz[N], vis1[N], vis2[N], ver[N];
int cur_f = 0, mx_f = 0;

int set_sz(int cur, int last, int t)
{
    vis1[cur] = vis2[cur] = t;
    ver[t] = cur;
    sz[cur] = 1;
    for (int e : g[cur])
    {
        if (e != last)
        {
            vis2[cur] = max(vis2[cur], set_sz(e, cur, vis2[cur] + 1));
            sz[cur] += sz[e];
        }
    }
    return vis2[cur];
}

int sack(int cur, int last, bool keep)
{
    int mx = -1, big = -1, res = 0;
    for (int e : g[cur])
        if (e != last && sz[e] > mx)
            mx = sz[e], big = e;
    for (int e : g[cur])
        if (e != last && e != big)
            res += sack(e, cur, false);
    if (big != -1)
        res += sack(big, cur, true);
    cur_cap[F[cur]]++;
    if (cur_cap[F[cur]] == 1)
        cur_f++;
    if (cur_cap[F[cur]] == cap[F[cur]])
        mx_f++;
    for (int e : g[cur])
    {
        if (e != last && e != big)
        {
            for (int i = vis1[e]; i <= vis2[e]; i++)
            {
                cur_cap[F[ver[i]]]++;
                if (cur_cap[F[ver[i]]] == 1)
                    cur_f++;
                if (cur_cap[F[ver[i]]] == cap[F[ver[i]]])
                    mx_f++;
            }
        }
    }
    // d(cur, cur_f, mx_f);
    // for (int i = 1; i <= 2; i++)
    //     cout << i << " : " << cap[i] << " " << cur_cap[i] << "\n";
    if (cur != last && cur_f == mx_f)
        res++;
    if (!keep)
    {
        for (int i = vis1[cur]; i <= vis2[cur]; i++)
        {
            cur_cap[F[ver[i]]]--;
            if (cur_cap[F[ver[i]]] == 0)
                cur_f--;
            if (cur_cap[F[ver[i]]] == cap[F[ver[i]]] - 1)
                mx_f--;
        }
    }
    return res;
}

int solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        cap[i] = cur_cap[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> F[i];
        cap[F[i]]++;
    }
    cur_f = 0;
    mx_f = 0;
    set_sz(1, 1, 0);
    int res=0;
    // res += sack(1, 1, true);
    return n;
}

int main()
{
    freopen("test_input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}