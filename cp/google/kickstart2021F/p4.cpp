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

string DecimalToBinaryString(int a, int n)
{
    string binary = "";
    for (int i = 0; i < n; i++)
    {
        if ((a >> i) & 1)
            binary = "1" + binary;
        else
            binary = "0" + binary;
    }
    return binary;
}

ll solve()
{
    int n, m;
    ll k, res = 0;
    cin >> n >> m >> k;
    vector<int> l(n), r(n);
    vector<ll> a(n);
    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<ll>> dp(n, vector<ll>(1 << n));
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i] >> a[i];
        dp[i][1 << i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    for (int mask = 1; mask < (1 << n); mask++)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                sum += a[i];
        for (int last = 0; last < n; last++)
        {
            if ((mask >> last) & 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (((mask >> j) & 1) == 0)
                    {
                        bool sat = false;
                        for (int i = 0; !sat && i < n; i++)
                            if (((mask >> i) & 1) && g[i][j] && sum >= l[j] && sum <= r[j])
                                sat = true;
                        if (sat)
                            dp[j][mask | (1 << j)] += dp[last][mask];
                    }
                }
                if (sum == k && dp[last][mask] > 0)
                    res += dp[last][mask];
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
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": "
             << solve() << "\n";
    return 0;
}