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

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1), s(n + 1), drop(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i] >> s[i];
    for (int i = 1; i <= n; i++)
        drop[i] = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
    vector<int> tdp(n + 1), pdp(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pdp[i] = add(pdp[i], pdp[i - 1]);
        tdp[i] = add(tdp[i], add(x[i] - y[i], add(pdp[i], -pdp[drop[i] - 1])));
        pdp[i] = add(pdp[i], tdp[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = add(dp[i], add(dp[i - 1], x[i] - x[i - 1]));
        if (s[i])
            dp[i] = add(dp[i], tdp[i]);
    }
    return add(dp[n], 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}