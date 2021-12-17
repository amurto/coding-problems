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

const int N = 2e5 + 5, LGN = 19;
vector<int> g[N];
int par[N], ind[N], dep[N], up[N][LGN + 1], tin[N], tout[N], timer = 0;

int combine1(int x, int y)
{
    // use your combiner here
    return min(x, y);
}

int combine2(int x, int y)
{
    // use your combiner here
    return max(x, y);
}
struct sparse_table
{
    vector<vector<int>> sp1, sp2;
    vector<int> hp;
    sparse_table(int n)
    {
        sp1.resize(n, vector<int>(LGN));
        sp2.resize(n, vector<int>(LGN));
        hp.resize(n + 1);
        // highest power of 2 less than i
        hp[0] = hp[1] = 0;
        for (int i = 2; i <= n; i++)
            hp[i] = hp[i / 2] + 1;
    }
    sparse_table() = default;

    void build(vector<int> &arr, int n)
    {
        // sparse table initialization with input array
        for (int i = 0; i < n; i++)
            sp1[i][0] = sp2[i][0] = arr[i];
        // works for min, max, gcd
        // updates not supported
        for (int k = 1; k < LGN; k++)
        {
            for (int i = 0; i < n; i++)
            {
                sp1[i][k] = combine1(sp1[i][k - 1], sp1[min(n - 1, i + (1 << (k - 1)))][k - 1]);
                sp2[i][k] = combine2(sp2[i][k - 1], sp2[min(n - 1, i + (1 << (k - 1)))][k - 1]);
            }
        }
    }

    int query1(int l, int r)
    {
        int dis = r - l + 1;
        return combine1(sp1[l][hp[dis]], sp1[r - (1 << hp[dis]) + 1][hp[dis]]);
    }

    int query2(int l, int r)
    {
        int dis = r - l + 1;
        return combine2(sp2[l][hp[dis]], sp2[r - (1 << hp[dis]) + 1][hp[dis]]);
    }
};

void dfs(int cur, int dd)
{
    tin[cur] = ++timer;
    ind[tin[cur]] = cur;
    dep[cur] = dd;
    up[cur][0] = par[cur];
    for (int i = 1; i <= LGN; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    for (int e : g[cur])
        dfs(e, dd + 1);
    tout[cur] = timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (u == v)
        return u;
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LGN; i >= 0; i--)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

int ask_lca(sparse_table &st, int l, int r)
{
    int mn = ind[st.query1(l, r)], mx = ind[st.query2(l, r)];
    return lca(mn, mx);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    par[0] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> par[i];
        par[i]--;
        g[par[i]].pb(i);
    }
    dfs(0, 0);
    vector<int> tm(n);
    for (int i = 0; i < n; i++)
        tm[i] = tin[i];
    sparse_table st(n);
    st.build(tm, n);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int mn = ind[st.query1(l, r)], mx = ind[st.query2(l, r)];
        int ans = lca(mn, mx), mn_ans = -1, mx_ans = -1, rem = mn;
        if (mn == l)
            mn_ans = ask_lca(st, l + 1, r);
        else if (mn == r)
            mn_ans = ask_lca(st, l, r - 1);
        else
            mn_ans = lca(ask_lca(st, l, mn - 1), ask_lca(st, mn + 1, r));
        if (mx == l)
            mx_ans = ask_lca(st, l + 1, r);
        else if (mx == r)
            mx_ans = ask_lca(st, l, r - 1);
        else
            mx_ans = lca(ask_lca(st, l, mx - 1), ask_lca(st, mx + 1, r));
        if (dep[mn_ans] > dep[ans])
        {
            rem = mn;
            ans = mn_ans;
        }
        if (dep[mx_ans] > dep[ans])
        {
            rem = mx;
            ans = mx_ans;
        }
        cout << rem + 1 << " " << dep[ans] << "\n";
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