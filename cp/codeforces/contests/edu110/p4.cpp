#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = (1 << 19);
vector<int> g[N], tin(N), tout(N), dep(N), sub(N);

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int set_timer(int cur, int t, int lvl)
{
    tin[cur] = tout[cur] = t;
    dep[cur] = lvl;
    int mx = tin[cur];
    for (int e : g[cur])
        tout[cur] = set_timer(e, tout[cur] + 1, lvl + 1);
    return tout[cur];
}

void precompute(string &str, int cur)
{
    if (g[cur].empty())
    {
        sub[cur] = 1;
        if (str[cur] == '?')
            sub[cur] = 2;
        return;
    }
    precompute(str, g[cur][0]);
    precompute(str, g[cur][1]);
    if (str[cur] == '0')
        sub[cur] = sub[g[cur][0]];
    else if (str[cur] == '1')
        sub[cur] = sub[g[cur][1]];
    else
        sub[cur] = sub[g[cur][0]] + sub[g[cur][1]];
}

void dfs(string &str, int cur, int id)
{
    if (id == cur)
    {
        if (g[cur].empty())
        {
            sub[cur] = 1;
            if (str[cur] == '?')
                sub[cur] = 2;
        }
        else
        {
            if (str[cur] == '0')
                sub[cur] = sub[g[cur][0]];
            else if (str[cur] == '1')
                sub[cur] = sub[g[cur][1]];
            else
                sub[cur] = sub[g[cur][0]] + sub[g[cur][1]];
        }
        return;
    }
    if (is_ancestor(g[cur][0], id))
        dfs(str, g[cur][0], id);
    else
        dfs(str, g[cur][1], id);
    if (str[cur] == '0')
        sub[cur] = sub[g[cur][0]];
    else if (str[cur] == '1')
        sub[cur] = sub[g[cur][1]];
    else
        sub[cur] = sub[g[cur][0]] + sub[g[cur][1]];
}

void solve()
{
    int k, q, id;
    char ch;
    string str;
    cin >> k >> str >> q;
    int n = (1 << k);
    vector<int> prev(n);
    prev[n - 2] = 1;
    int p = n - 3;
    for (int i = n - 2; i >= 0; i--)
    {
        int l = p - 1, r = p;
        if (l >= 0 && r >= 0)
        {
            g[i].pb(l);
            g[i].pb(r);
            p -= 2;
        }
    }
    int root = n - 2;
    set_timer(root, 0, 0);
    precompute(str, root);
    for (int i = 0; i < q; i++)
    {
        cin >> id >> ch;
        id--;
        str[id] = ch;
        dfs(str, root, id);
        cout << sub[root] << "\n";
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