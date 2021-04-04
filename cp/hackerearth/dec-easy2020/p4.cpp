#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

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

int solve()
{
    int n, res = 1;
    cin >> n;
    vector<int> l(n + 1), r(n + 1), dp(n + 1), pdp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    dp[0] = pdp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int prev = lower_bound(r.begin(), r.end(), l[i]) - r.begin();
        if (prev == i)
        {
            res = mul(res, dp[i - 1]);
            dp[i] = 1;
        }
        else
            dp[i] = add(pdp[i - 1], -pdp[prev - 1]);
        pdp[i] = add(pdp[i - 1], dp[i]);
    }
    res = mul(res, dp[n]);
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