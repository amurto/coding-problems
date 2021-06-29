// https://codeforces.com/contest/54/problem/C
// First Digit Law

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e18;
ll ones(ll v)
{
    if (v == 0)
        return 0;
    if (v < 10)
        return 1;
    ll cur = 1, res = 0;
    while (cur <= v / 10)
    {
        res += cur;
        cur *= 10;
    }
    res += min(2 * cur - 1, v) - cur + 1;
    return res;
}

double solve()
{
    int n, k;
    cin >> n;
    vector<ll> l(n), r(n), cnt(n);
    vector<double> p(n), q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        cnt[i] = ones(r[i]) - ones(l[i] - 1);
        p[i] = (1.0 * cnt[i]) / (1.0 * (r[i] - l[i] + 1));
        q[i] = 1.0 - p[i];
    }
    cin >> k;
    vector<vector<double>> dp(n, vector<double>(n + 1));
    int req = (k * n + 99) / 100;
    dp[0][0] = q[0];
    dp[0][1] = p[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] * q[i];
        for (int j = 1; j <= i + 1; j++)
            dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * q[i];
    }
    double res = 0;
    for (int j = 0; j <= n; j++)
        if (j >= req)
            res += dp[n - 1][j];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}