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

const int B = 30;

struct dsu
{
    int n;
    vector<int> parent, cap;
    dsu(int l)
    {
        n = l;
        parent.resize(n + 1);
        cap.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            cap[i] = 1;
        }
    }

    int root(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = root(parent[x]);
    }

    void merge_nodes(int x, int y)
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
};

void solve()
{
    int n, m, t;
    cin >> n >> m;
    vector<int> U(m), V(m), W(m);
    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> U[i] >> V[i] >> W[i];
        g[U[i]].pb({V[i], W[i]});
        g[V[i]].pb({U[i], W[i]});
    }
    vector<vector<int>> rt(B, vector<int>(n + 1));
    vector<vector<bool>> bitvis(B, vector<bool>(n + 1));
    for (int b = 0; b < B; b++)
    {
        dsu ds(n + 1);
        for (int i = 0; i < m; i++)
            if ((W[i] >> b) & 1)
                ds.merge_nodes(U[i], V[i]);
        for (int i = 1; i <= n; i++)
            rt[b][i] = ds.root(i);
        if (b > 0)
        {
            vector<vector<bool>> vis(4, vector<bool>(n + 1));
            queue<pii> q;
            for (int i = 0; i < m; i++)
            {
                int val = 0;
                val |= (W[i] & 1);
                val |= (((W[i] >> b) & 1) << 1);
                if (val == 0 || val == 2)
                {
                    if (!vis[val][U[i]])
                    {
                        vis[val][U[i]] = true;
                        q.push({U[i], val});
                    }
                    if (!vis[val][V[i]])
                    {
                        vis[val][V[i]] = true;
                        q.push({V[i], val});
                    }
                }
            }
            while (!q.empty())
            {
                pii cur = q.front();
                q.pop();
                for (pii e : g[cur.first])
                {
                    int val = cur.second, e_val = 0;
                    e_val |= (e.second & 1);
                    e_val |= (((e.second >> b) & 1) << 1);
                    if (e_val != 1)
                    {
                        val &= e_val;
                        if (val != 1 && !vis[val][e.first])
                        {
                            vis[val][e.first] = true;
                            q.push({e.first, val});
                        }
                    }
                }
            }
            for (int i = 1; i <= n; i++)
                if (vis[0][i] || vis[2][i])
                    bitvis[b][i] = true;
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int l, r, ans = 2;
        cin >> l >> r;
        for (int b = 0; b < B; b++)
            if (rt[b][l] == rt[b][r])
                ans = 0;
        if (ans > 0)
        {
            for (int b = 0; b < B; b++)
                if (bitvis[b][l])
                    ans = 1;
        }
        cout << ans << "\n";
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