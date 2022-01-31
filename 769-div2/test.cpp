#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5, LGN = 20;
vector<int> g[N];
int tin[N], tout[N], dep[N], dp[N], par[N], pre[N], suf[N];
int sum = 0;
int precompute(int cur, int last, int t, int dd)
{
    par[cur] = last;
    dp[cur] = 0;
    tin[cur] = tout[cur] = t;
    dep[cur] = dd;
    for (int e : g[cur])
    {
        if (e != last)
        {
            tout[cur] = precompute(e, cur, tout[cur] + 1, dd + 1);
            dp[cur] = max(dp[cur], dp[e] + 1);
        }
    }
    pre[tin[cur]] = dep[cur];
    suf[tin[cur]] = dep[cur];
    return tout[cur];
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int dfs(int cur, int pmx, int x, int n)
{
    int lmx = 0, rmx = 0;
    if (tin[cur] > 0)
        lmx = pre[tin[cur] - 1];
    if (tin[cur] < n - 1)
        rmx = suf[tout[cur] + 1];
    int ans = max(dp[cur] + min(dep[cur], x), min(max(lmx, rmx), pmx + min(dep[cur], x)));
    array<int, 2> cnt{0, 0};
    for (int e : g[cur])
    {
        if (e != par[cur])
        {
            cnt[1] = max(cnt[1], dp[e] + 1);
            if (cnt[1] > cnt[0])
                swap(cnt[0], cnt[1]);
        }
    }
    for (int e : g[cur])
    {
        if (e != par[cur])
        {
            int far = cnt[0];
            if (dp[e] + 1 == far)
                far = cnt[1];
            ans = min(ans, dfs(e, max(pmx, far) + 1, x, n));
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        tin[i] = tout[i] = dep[i] = dp[i] = par[i] = pre[i] = suf[i] = 0;
        g[i].clear();
    }

    int prev_sum = sum;
    sum += n;
    if (sum >= 241)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            cout << u << v;
            g[u].pb(v);
            g[v].pb(u);
        }
        cout << " ";
        return;
    }

    vector<int> res(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    precompute(1, 1, 0, 0);

    // for (int i = 0; i < n; i++)
    //     cout << pre[i] << " ";
    // cout << "\n";
    // for (int i = 0; i < n; i++)
    //     cout << suf[i] << " ";
    for (int i = 1; i < n; i++)
        pre[i] = max(pre[i - 1], pre[i]);
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i], suf[i + 1]);

    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx = max(mx, dep[i]);
    // vector<int> leaves;
    // for (int i = 1; i <= n; i++)
    //     if (dep[i] == mx)
    //         leaves.pb(i);

    for (int i = 1; i <= n; i++)
        res[i] = mx;

    for (int i = 1; i <= n; i++)
        res[i] = min(res[i], dfs(1, 0, i, n));

    for (int i = 1; i <= n; i++)
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