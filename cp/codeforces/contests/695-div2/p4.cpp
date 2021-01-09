#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5005, MOD = 1e9 + 7;
int dp[N][N], c[N], n, k, q, res = 0;

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

int sop(int cur, int rem)
{
    if (cur < 0 || cur >= n)
        return 0;
    if (rem == 0)
        return 1;
    if (dp[cur][rem] == -1)
        dp[cur][rem] = add(sop(cur - 1, rem - 1), sop(cur + 1, rem - 1));
    return dp[cur][rem];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k >> q;
    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
            val[i] = add(val[i], mul(sop(i, j), sop(i, k - j)));
        res = add(res, mul(val[i], c[i]));
    }
    while (q-- > 0)
    {
        int idx, nc;
        cin >> idx >> nc;
        idx--;
        res = add(res, -1 * mul(val[idx], c[idx]));
        c[idx] = nc;
        res = add(res, mul(val[idx], c[idx]));
        cout << res << "\n";
    }
    return 0;
}