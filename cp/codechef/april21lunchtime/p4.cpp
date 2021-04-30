#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 2e5 + 5, LGN = 19;
vector<int> g[N];
int up[N][LGN + 1], tin[N], tout[N], dep[N], sub[N], near[N], timer = 0;
bool sp[N];

void init(int n)
{
    timer = 0;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        sp[i] = false;
        near[i] = -1;
    }
}

int dfs(int cur, int last, int d)
{
    sub[cur] = 0;
    near[cur] = near[last];
    if (sp[cur])
    {
        sub[cur]++;
        near[cur] = cur;
    }
    tin[cur] = ++timer;
    dep[cur] = d;
    up[cur][0] = last;
    for (int i = 1; i <= LGN; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    for (int e : g[cur])
        if (e != last)
            sub[cur] += dfs(e, cur, d + 1);
    tout[cur] = timer;
    return sub[cur];
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

int k_ancestor(int u, int k)
{
    int d = dep[u], tmp = k;
    for (int i = LGN; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            u = up[u][i];
            k -= (1 << i);
        }
    }
    return (d - dep[u] == tmp) ? u : -1;
}

int inside(vector<int> &f, vector<int> &tmp, int b)
{
    int lb = lower_bound(tmp.begin(), tmp.end(), tin[b]) - tmp.begin();
    if (lb < tmp.size() && is_ancestor(b, f[lb]))
        return f[lb];
    return -1;
}

int outside(vector<int> &f, vector<int> &tmp, int b)
{
    if (tmp[0] < tin[b])
        return f[0];
    if (tmp.back() > tout[b])
        return f.back();
    return -1;
}

int outsideLR(vector<int> &f, vector<int> &tmp, int l, int r)
{
    if (tin[l] > tin[r])
        swap(l, r);
    if (tmp[0] < tin[l])
        return f[0];
    if (tmp.back() > tout[r])
        return f.back();
    int b = lower_bound(tmp.begin(), tmp.end(), tin[r]) - tmp.begin();
    b--;
    if (b >= 0 && tmp[b] > tout[l])
        return f[b];
    return -1;
}
void solve()
{
    int n, k, a, u, v;
    cin >> n >> k >> a;
    init(n);
    vector<int> f(k), tmp(k);
    vector<pii> res;
    for (int i = 0; i < k; i++)
    {
        cin >> f[i];
        sp[f[i]] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1, 0);
    sort(f.begin(), f.end(), [&](int &i1, int &i2) {
        return tin[i1] <= tin[i2];
    });
    for (int i = 0; i < k; i++)
        tmp[i] = tin[f[i]];
    int mn = f[0];
    for (int e : f)
        if (dep[e] <= dep[mn])
            mn = e;
    for (int b = 1; b <= n; b++)
    {
        if (a == b)
        {
            res.pb({0, f[0]});
            continue;
        }
        int anc = lca(a, b);
        int dis = dep[a] - dep[anc] + dep[b] - dep[anc];
        int mx = -dis, p = f[0];
        if (anc == a)
        {
            if (sub[b] > 0)
            {
                mx = dis;
                p = inside(f, tmp, b);
            }
            else if (near[b] >= 0 && dep[near[b]] >= dep[a])
            {
                mx = dep[near[b]] - dep[a] - (dep[b] - dep[near[b]]);
                p = near[b];
            }
            else
            {
                mx = -dis;
                p = f[0];
            }
        }
        else if (anc == b)
        {
            int l = k_ancestor(a, dep[a] - dep[b] - 1);
            if (outside(f, tmp, l) >= 0)
            {
                mx = dis;
                p = outside(f, tmp, l);
            }
            else if (dep[mn] <= dep[a])
            {
                mx = dep[a] - dep[mn] - (dep[mn] - dep[b]);
                p = mn;
            }
            else
            {
                mx = -dis;
                p = f[0];
            }
        }
        else
        {
            if (sub[b] > 0)
            {
                mx = dis;
                p = inside(f, tmp, b);
            }
            else
            {
                int l = k_ancestor(a, dep[a] - dep[anc] - 1), r = k_ancestor(b, dep[b] - dep[anc] - 1);
                int o = outsideLR(f, tmp, l, r);
                if (o >= 0)
                {
                    mx = dis;
                    p = o;
                }
                else
                {
                    int cl = near[b];
                    if (cl >= 0)
                    {
                        if (dep[cl] >= dep[anc])
                        {
                            mx = dis - 2 * (dep[b] - dep[cl]);
                            p = near[b];
                        }
                        else
                        {
                            mx = dep[a] - dep[anc] - (dep[b] - dep[anc]);
                            p = near[b];
                        }
                    }
                    else
                    {
                        if (dep[mn] < dep[a])
                        {
                            mx = dep[a] - dep[mn] - (dep[mn] - dep[anc] + dep[b] - dep[anc]);
                            p = mn;
                        }
                        else
                        {
                            mx = -dis;
                            p = f[0];
                        }
                    }
                }
            }
        }
        res.pb({mx, p});
    }
    for (int i = 0; i < n; i++)
        cout << res[i].first << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << res[i].second << " ";
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