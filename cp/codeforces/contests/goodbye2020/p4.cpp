#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
ll W[N], res[N];

void solve()
{
    ll sum = 0;
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> W[i];
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    priority_queue<ll> pq;
    for (int i = 1; i <= n; i++)
    {
        int deg = g[i].size();
        while (deg-- > 1)
            pq.push(W[i]);
        sum += W[i];
    }
    res[1] = sum;
    for (int i = 2; i <= n - 1; i++)
    {
        res[i] = res[i - 1];
        if (pq.empty())
            continue;
        res[i] += pq.top();
        pq.pop();
    }
    for (int i = 1; i <= n - 1; i++)
        cout << res[i] << " ";
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