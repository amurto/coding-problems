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

const int N = 1e5 + 5;
vector<int> g[N];
int arr[N], dp[N], disA[N], disB[N], par[N];

void calc_dis(int cur, int last, int t, int dep)
{
    if (t == 0)
    {
        disA[cur] = dep;
        par[cur] = last;
    }
    else
        disB[cur] = dep;
    for (int e : g[cur])
        if (e != last)
            calc_dis(e, cur, t, dep + 1);
}

void dfs(int cur, int last, int val)
{
    dp[cur] = __gcd(val, arr[cur]);
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, dp[cur]);
}

int dfs1(int cur, int last, int val)
{
    int ans = 0;
    dp[cur] = __gcd(val, arr[cur]);
    for (int e : g[cur])
        if (e != last && arr[e] != 0)
            ans = max(ans, dfs1(e, cur, dp[cur]));
    if (g[cur].size() == 1 && g[cur][0] == last)
        ans = max(ans, dp[cur]);
    return ans;
}

int dfs2(int cur, int last, int val)
{
    int ans = 1e9 + 5;
    dp[cur] = __gcd(val, arr[cur]);
    for (int e : g[cur])
    {
        if (e != last)
        {
            ans = min(ans, dfs2(e, cur, dp[cur]));
        }
    }
    ans = dp[cur];
    return ans;
}

int solve()
{
    int n, a, b, a_res = 0, res = 1e9 + 5;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> a >> b;
    calc_dis(a, a, 0, 0);
    calc_dis(b, b, 1, 0);
    dfs(a, a, 0);
    int tmp = b, last = b;
    while (disA[tmp] > disB[tmp])
    {
        arr[tmp] = 0;
        int cnt = 0;
        for (int e : g[tmp])
            if (e != par[tmp] && e != last)
                cnt++;
        if (cnt > 0)
            res = min(res, dp[par[tmp]]);
        last = tmp;
        tmp = par[tmp];
    }
    res = min(res, dp[tmp]);
    a_res = dfs1(a, a, 0);
    res = min(res, dfs2(a, a, 0));
    res = max(res, a_res);
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