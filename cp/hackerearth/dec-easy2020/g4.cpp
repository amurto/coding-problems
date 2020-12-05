#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MOD = 1000000007, N = 3e5 + 1;

ll add(ll x, ll y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll sub(ll x, ll y)
{
    if (x - y < 0)
        return x - y + MOD;
    return x - y;
}

ll mul(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

ll dp[N][2];

ll iu(vector<pair<ll, ll>> &iv, vector<bool> &rem, int cur, int r)
{
    if (cur == iv.size())
        return 1;
    if (dp[cur][r] == -1)
    {
        if (r == 0)
        {
            ll c0 = 0, c1 = 0;
            c0 = iu(iv, rem, cur + 1, 0);
            if (rem[cur])
                c1 = iu(iv, rem, cur + 1, 1);
            dp[cur][r] = add(c0, c1);
        }
        else
        {
            dp[cur][r] = iu(iv, rem, cur + 1, 0);
        }
        dp[cur][r] = add(dp[cur][r], 0);
    }
    return dp[cur][r];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    vector<pair<ll, ll>> iv(n);
    for (int i = 0; i < n; i++)
        cin >> iv[i].first >> iv[i].second;
    sort(iv.begin(), iv.end());
    vector<bool> rem(n);
    for (int i = 1; i < n - 1; i++)
    {
        if (iv[i - 1].second >= iv[i + 1].first)
            rem[i] = true;
    }
    cout << iu(iv, rem, 0, 0) << "\n";
    return 0;
}