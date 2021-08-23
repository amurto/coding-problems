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

const int MOD = 998244353, N = 20;

int two[N];
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

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    int c = n - 1;
    vector<int> g(n), dp(1 << n), cnt(n);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u] |= (1 << v);
        g[v] |= (1 << u);
    }
    d(g);
    dp[1] = 1;
    for (int i = 0; i < (1 << c); i++)
    {
        int cur = i * 2 + 1;
        for (int b = 1; b < n; b++)
        {
            if ((cur >> b) & 1)
            {
                dp[cur] = add(dp[cur], mul(add(two[__builtin_popcount(g[b] & cur)], -1), dp[cur ^ (1 << b)]));
            }
        }
        for (int b = 1; b < n; b++)
            if ((cur >> b) & 1)
                cnt[b] = add(cnt[b], dp[cur]);
        d(cur, dp[cur]);
    }
    for (int i = 1; i < n; i++)
        cout << cnt[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = mul(two[i - 1], 2);
    solve();
    return 0;
}