// https://codeforces.com/contest/587/problem/C
// Duff in the Army
 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5, LGN = 18;
vector<int> g[N], p[N];
int up[N][LGN + 1], tin[N], tout[N], dep[N], timer = 0;
vector<int> seq[N][LGN + 1];

vector<int> merge(vector<int> arr1, vector<int> arr2)
{
    int sz1 = arr1.size(), sz2 = arr2.size(), i = 0, j = 0, cur = 0;
    vector<int> tmp;
    for (int a : arr1)
        tmp.pb(a);
    for (int a : arr2)
        tmp.pb(a);
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    int k = min(10, (int)tmp.size());
    vector<int> arr(k);
    for (int i = 0; i < k; i++)
        arr[i] = tmp[i];
    return arr;
}

void dfs(int cur, int last, int d)
{
    tin[cur] = ++timer;
    dep[cur] = d;
    up[cur][0] = last;
    seq[cur][0] = merge(p[cur], p[last]);
    for (int i = 1; i <= LGN; i++)
    {
        seq[cur][i] = merge(seq[cur][i - 1], seq[up[cur][i - 1]][i - 1]);
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    }
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, d + 1);
    tout[cur] = timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LGN; i >= 0; i--)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

vector<int> bs(int u, int k)
{
    vector<int> tmp = p[u];
    for (int i = LGN; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            tmp = merge(tmp, seq[u][i]);
            u = up[u][i];
            k -= (1 << i);
        }
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q, u, v, a;
    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u;
        p[u].pb(i);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(p[i].begin(), p[i].end());
        vector<int> tmp;
        p[i] = merge(p[i], tmp);
    }
    dfs(1, 1, 0);
    while (q-- > 0)
    {
        cin >> u >> v >> a;
        int anc = lca(u, v);
        vector<int> res = merge(bs(u, dep[u] - dep[anc]), bs(v, dep[v] - dep[anc]));
        a = min(a, (int)res.size());
        cout << a << " ";
        for (int i = 0; i < a; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
    return 0;
}