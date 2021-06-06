#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

const ll inf = 1e18;

class edge
{
public:
    int v;
    ll c, d, rt;
    edge() {}
    edge(int v, ll c, ll d, ll rt) : v(v), c(c), d(d), rt(rt) {}
};

ll sq_root(ll x)
{
    ll l = 0, r = 2e9 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

ll solve()
{
    int n, m, u, v;
    ll c, d;
    cin >> n >> m;
    vector<vector<edge>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c >> d;
        g[u].pb(edge(v, c, d, sq_root(d)));
        g[v].pb(edge(u, c, d, sq_root(d)));
    }
    multiset<pair<ll, ll>> ms;
    vector<ll> dis(n + 1, inf);
    vector<bool> vis(n + 1);
    ms.insert({0, 1});
    dis[1] = 0;
    while (!ms.empty())
    {
        pii cur = *ms.begin();
        ms.erase(ms.begin());
        if (!vis[cur.second])
        {
            vis[cur.second] = true;
            if (cur.second == n)
                return dis[n];
            for (edge e : g[cur.second])
            {
                if (!vis[e.v])
                {
                    ll tt = max(cur.first, e.rt);
                    ll mn = tt + e.d / (tt + 1);
                    if (e.c + mn < dis[e.v])
                    {
                        dis[e.v] = e.c + mn;
                        ms.insert({dis[e.v], e.v});
                    }
                }
            }
        }
    }
    return dis[n] >= inf ? -1 : dis[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}