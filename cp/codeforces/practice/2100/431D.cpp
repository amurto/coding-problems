// https://codeforces.com/contest/431/problem/D
// Random Task

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 62;
ll dp[N][N];

void init()
{
    for (int i = 0; i < N; i++)
        dp[i][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
}

ll f(ll mx, int k)
{
    ll res = 0;
    vector<int> digs;
    while (mx > 0)
    {
        digs.pb(mx % 2);
        mx /= 2;
    }
    reverse(digs.begin(), digs.end());
    res += (count(digs.begin(), digs.end(), 1) == k);
    for (int i = 0, j = digs.size(); k >= 0 && i < digs.size(); i++, j--)
    {
        if (digs[i])
            res += dp[j - 1][k];
        k -= digs[i];
    }
    return res;
}

ll solve()
{
    ll m;
    int k;
    cin >> m >> k;
    ll low = 1, high = 1e18;
    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        ll v = f(2 * mid, k) - f(mid, k);
        if (v >= m)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
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