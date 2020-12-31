#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5e5 + 1, MOD = 1e9 + 7;
int g[N][2], parent[N], cap[N];
bool vis[N];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        g[i][0] = g[i][1] = cap[i] = 0;
        vis[i] = false;
    }
}

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

bool merge(int rx, int ry)
{
    rx = root(rx);
    ry = root(ry);
    if (rx == ry)
        return false;
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
            cin >> g[i][j];
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (g[i][1] == 0)
        {
            int rt = root(g[i][0]);
            if (!vis[rt])
            {
                res.pb(i);
                vis[rt] = true;
            }
        }
        else
        {
            int rx = root(g[i][0]), ry = root(g[i][1]);
            if (rx != ry)
            {
                if (!vis[rx] || !vis[ry])
                {
                    vis[rx] |= vis[ry];
                    merge(g[i][0], g[i][1]);
                    res.pb(i);
                }
            }
        }
    }
    int sz = res.size(), ans = 1;
    for (int i = 0; i < sz; i++)
        ans = (ans * 1ll * 2) % MOD;
    cout << ans << " " << sz << "\n";
    for (int r : res)
        cout << r << " ";
    return 0;
}