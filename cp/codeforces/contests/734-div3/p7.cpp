#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 105;
vector<int> g[N];
int dep[N];

int add(int x, int y)
{
    x += y;
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

void dfs(int cur, int last, int p)
{
    dep[cur] = p;
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, p ^ 1);
}

void traverse(vector<int> &sub, int cur, int last, int p)
{
    sub[p]++;
    for (int e : g[cur])
        if (e != last)
            traverse(sub, e, cur, p + 1);
}

int solve()
{
    int n, k, u, v, res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1, 0);
    vector<int> cnt(2);
    for (int i = 1; i <= n; i++)
        cnt[dep[i]]++;
    if (k == 2)
        res = add(res, mul(cnt[0], cnt[1]));
    for (int cur = 1; cur <= n; cur++)
    {
        vector<vector<int>> st(n + 1);
        for (int e : g[cur])
        {
            vector<int> sub(n + 1);
            traverse(sub, e, cur, 1);
            for (int j = 1; j <= n; j++)
                if (sub[j] > 0)
                    st[j].pb(sub[j]);
        }
        for (int dis = 1; dis <= n; dis++)
        {
            if ((int)st[dis].size() >= k)
            {
                int sz = st[dis].size();
                vector<vector<int>> dp(sz + 1, vector<int>(k + 1));
                for (int i=0; i<=sz; i++)
                    dp[i][0] = 1;
                for (int i = 1; i <= sz; i++)
                    for (int j = 1; j <= min(k, i); j++)
                        dp[i][j] = add(dp[i][j], add(dp[i - 1][j], mul(st[dis][i - 1], dp[i - 1][j - 1])));
                res = add(res, dp[sz][k]);
            }
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