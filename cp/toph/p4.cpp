#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 100000110059;

ll mul(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    return (x * y) % MOD;
}
void bfs(vector<vector<int>> &g, vector<int> &arr, int n, int x)
{
    int m = 0, inf = 1e7;
    vector<int> mark(n + 1), dis(n + 1, inf);
    vector<ll> ways(x + 1);
    for (int i = 1; i <= x; i++)
        mark[arr[i]] = i;
    queue<pair<int, int>> q;
    for (int i = x; i > 1; i--)
        q.push({arr[i], arr[i - 1]});
    while (!q.empty())
    {
        int len = q.size();
        while (len-- > 0)
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first == cur.second && dis[cur.first] >= m)
            {
                dis[cur.first] = m;
                ways[mark[cur.first]]++;
                continue;
            }
            if (mark[cur.second] > 0 && dis[cur.second] < inf)
                continue;
            for (int e : g[cur.first])
            {
                if (e != cur.second && mark[e] > 0)
                    continue;
                q.push({e, cur.second});
            }
        }
        m++;
    }
    ll cost = 0, w = 1;
    for (int i = 1; i < x; i++)
    {
        if (dis[arr[i]] >= inf)
        {
            cout << "-1\n";
            return;
        }
        cost += 1ll * dis[arr[i]];
        w = mul(w, ways[i]);
    }
    cout << cost << " " << w << "\n";
}

void solve()
{
    int n, m, x, u, v;
    cin >> n >> m >> x;
    vector<vector<int>> g(n + 1);
    vector<int> arr(x + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[v].pb(u);
    }
    for (int i = 1; i <= x; i++)
        cin >> arr[i];
    bfs(g, arr, n, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}