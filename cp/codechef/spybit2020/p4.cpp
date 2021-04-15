#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back

const int N = 1e5 + 5;
vector<pii> g[N];

void dfs(vector<ll> &cost, int cur, int last, int d, ll energy)
{
    cost[cur] = energy;
    for (pii e : g[cur])
        if (e.first != last)
            dfs(cost, e.first, cur, d + 1, energy + e.second * d);
}

int solve()
{
    int n, m, u, v, res = 0;
    ll k;
    cin >> n >> m;
    vector<ll> arr(m), cost(n + 1), leaf;
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    multiset<ll> ms(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> k;
        g[u].pb({v, k});
        g[v].pb({u, k});
    }
    dfs(cost, 1, -1, 1, 0);
    for (int i = 2; i <= n; i++)
        if (g[i].size() == 1)
            leaf.pb(cost[i]);
    sort(leaf.rbegin(), leaf.rend());
    for (ll l : leaf)
    {
        auto it = ms.lower_bound(l);
        if (it != ms.end())
        {
            res++;
            ms.erase(it);
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