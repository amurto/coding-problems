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

ll solve()
{
    ll n, m;
    cin >> n >> m;
    ll res = 1,dis=0;
    vector<ll> dp(21);
    vector<bool> is_cnt(20 * m + 1);
    for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (is_cnt[i * j] == 0)
            {
                dis++;
                is_cnt[i * j] = 1;
            }
        }
        dp[i] = dis;
    }
    vector<bool> vis(n + 1);
    for (ll i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            int cnt = 0;
            for (ll j = i; j <= n; j *= i)
            {
                vis[j] = true;
                cnt++;
            }
            res += dp[cnt];
        }
    }
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