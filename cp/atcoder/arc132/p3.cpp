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

const int MOD = 998244353, N = 505, B = 18;
int dp[N][1 << B];

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

int dfs(vector<int> &ids, vector<int> &vals, int cur, int mask, int diff, int sz)
{
    if (cur == sz)
        return 1;
    if (dp[cur][mask] == -1)
    {
        int bits = __builtin_popcount(mask);
        int last = cur - bits, res = 0;
        for (int i = last, b = 0; i < min(sz, last + B) && abs(ids[cur] - vals[i]) <= diff; i++, b++)
        {
            if (!((mask >> b) & 1))
            {
                int nmask = mask | (1 << b);
                while (nmask & 1)
                    nmask /= 2;
                res = add(res, dfs(ids, vals, cur + 1, nmask, diff, sz));
            }
        }
        dp[cur][mask] = res;
    }
    return dp[cur][mask];
}

int solve()
{
    int n, diff, res = 0;
    cin >> n >> diff;
    vector<int> arr(n + 1), ids, vals;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == -1)
            ids.pb(i);
        else
        {
            vis[arr[i]] = true;
            if (abs(arr[i] - i) > diff)
                return 0;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            vals.pb(i);
    int sz = (int)ids.size();
    memset(dp, -1, sizeof(dp));
    res = dfs(ids, vals, 0, 0, diff, sz);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}