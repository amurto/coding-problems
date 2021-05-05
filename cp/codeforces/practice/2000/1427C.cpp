// https://codeforces.com/contest/1427/problem/C
// The Hard Work of Paparazzi

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int ninf = -1e6;
int solve()
{
    int r, n;
    cin >> r >> n;
    vector<int> t(n + 1), x(n + 1), y(n + 1), dp(n + 1, ninf), pdp(n + 1, ninf);
    x[0] = y[0] = 1;
    dp[0] = pdp[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
    {
        if (i - 2 * r >= 0)
            dp[i] = max(dp[i], 1 + pdp[max(0, i - 2 * r)]);
        for (int j = i - 1; j >= max(0, i - 2 * r); j--)
            if (t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]))
                dp[i] = max(dp[i], dp[j] + 1);
        pdp[i] = max(pdp[i - 1], dp[i]);
    }
    return pdp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}