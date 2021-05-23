// https://codeforces.com/contest/1399/problem/E2
// Weights Division (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
class edge
{
public:
    int v, c;
    ll w;
    edge() {}
    edge(int v, ll w, int c) : v(v), w(w), c(c) {}
    bool operator<(const edge &other) const
    {
        return w < other.w;
    }
};

vector<edge> g[N];
ll dfs(vector<vector<ll>> &rem, ll &sum, ll path, int cur, int last)
{
    ll leaves = 0;
    if (g[cur].size() == 1 && g[cur][0].v == last)
    {
        sum += path;
        return 1;
    }
    for (edge e : g[cur])
    {
        if (e.v != last)
        {
            ll d = dfs(rem, sum, path + e.w, e.v, cur), w = e.w;
            leaves += d;
            while (w > 0)
            {
                rem[e.c].pb(w * d - (w / 2) * d);
                w >>= 1;
            }
        }
    }
    return leaves;
}

ll solve()
{
    int n, u, v, c = 1;
    ll t, w, sum = 0, res = 1e9;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w >> c;
        g[u].pb(edge(v, w, c - 1));
        g[v].pb(edge(u, w, c - 1));
    }
    vector<vector<ll>> rem(2);
    dfs(rem, sum, 0, 1, -1);
    if (sum <= t)
        return 0;
    for (int i = 0; i < 2; i++)
    {
        sort(rem[i].rbegin(), rem[i].rend());
        for (int j = 1; j < rem[i].size(); j++)
            rem[i][j] += rem[i][j - 1];
    }
    if (!rem[1].empty() && rem[1].back() >= sum - t)
    {
        int lb = lower_bound(rem[1].begin(), rem[1].end(), sum - t) - rem[1].begin();
        res = min(res, 2ll * lb + 2);
    };
    for (int i = 0; i < rem[0].size(); i++)
    {
        if (sum - rem[0][i] <= t)
            res = min(res, 1ll * i + 1);
        if (sum - rem[0][i] > t && !rem[1].empty() && rem[1].back() >= sum - rem[0][i] - t)
        {
            int lb = lower_bound(rem[1].begin(), rem[1].end(), sum - rem[0][i] - t) - rem[1].begin();
            res = min(res, 1ll * i + 1 + 2ll * lb + 2);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}