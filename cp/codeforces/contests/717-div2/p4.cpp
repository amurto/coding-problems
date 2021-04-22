#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1e5 + 5;

vector<int> g[N];
vector<pii> st[N];
set<int> path;

// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

vector<int> factorise(int x)
{
    vector<int> tmp;
    while (x > 1)
    {
        int d = lp[x];
        tmp.pb(d);
        while (x % d == 0)
            x /= d;
    }
    return tmp;
}

void dfs(vector<int> &dp, vector<int> &query, int cur, int par)
{
    path.insert(cur);
    for (pii p : st[cur])
    {
        auto it = path.lower_bound(p.first);
        it--;
        query[p.second] = dp[cur] - dp[*it];
    }
    for (int e : g[cur])
        if (e != par)
            dfs(dp, query, e, cur);
    path.erase(cur);
}

void solve()
{
    int n, q, l, r, mx = 0;
    cin >> n >> q;
    vector<int> arr(n + 1), prev(n + 1), dp(n + 1), last(N), query(q);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        vector<int> f = factorise(arr[i]);
        for (int e : f)
            mx = max(mx, last[e]);
        for (int e : f)
            last[e] = i;
        prev[i] = mx;
        g[prev[i]].pb(i);
        g[i].pb(prev[i]);
        dp[i] = dp[prev[i]] + 1;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        st[r].pb({l, i});
    }
    dfs(dp, query, 0, -1);
    for (int i = 0; i < q; i++)
        cout << query[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    solve();
    return 0;
}