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

const int MOD = 998244353, N = 1e5 + 5;

vector<int> divs[N];
vector<int> lp(N + 1), pr;
int mob[N];
void init()
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
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            divs[j].pb(i);
        if (i == 1)
            mob[i] = 1;
        else
        {
            if (lp[i / lp[i]] == lp[i])
                mob[i] = 0;
            else
                mob[i] = -1 * mob[i / lp[i]];
        }
    }
}

int add(int x, int y)
{
    x += y;
    x %= MOD;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n + 1), lens(N);
    vector<vector<int>> g(n + 1), dp(n + 1), st(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    // Lambda recursive function
    auto dfs = [&](const auto &self, int cur, int last) -> void
    {
        int val = arr[cur];
        int sz = (int)divs[val].size();
        dp[cur].resize(sz);
        st[cur].resize(sz);
        for (int j = 0; j < sz; j++)
        {
            st[cur][j] = add(st[cur][j], 1);
            dp[cur][j] = add(dp[cur][j], 1);
        }
        for (int e : g[cur])
        {
            if (e != last)
            {
                self(self, e, cur);
                for (int j = 0; j < (int)divs[arr[e]].size(); j++)
                {
                    if (val % divs[arr[e]][j] == 0)
                    {
                        int dv = divs[arr[e]][j];
                        int id = lower_bound(divs[val].begin(), divs[val].end(), dv) - divs[val].begin();
                        lens[dv] = add(lens[dv], add(mul(dp[e][j], st[cur][id]), dp[cur][id]));
                    }
                }
                for (int j = 0; j < (int)divs[arr[e]].size(); j++)
                {
                    if (val % divs[arr[e]][j] == 0)
                    {
                        int dv = divs[arr[e]][j];
                        int id = lower_bound(divs[val].begin(), divs[val].end(), dv) - divs[val].begin();
                        st[cur][id] = add(st[cur][id], st[e][j]);
                        dp[cur][id] = add(dp[cur][id], add(st[e][j], dp[e][j]));
                    }
                }
            }
        }
    };
    dfs(dfs, 1, 1);
    for (int i = 1; i < N; i++)
    {
        if (lens[i] > 0)
        {
            int tot = 0;
            for (int j = i, t = 1; j < N; j += i, t++)
                if (mob[t] != 0)
                    tot = add(tot, mul(mob[t], lens[j]));
            res = add(res, mul(i, tot));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}