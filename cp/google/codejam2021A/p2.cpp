#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int M = 100;
const ll LIM = 3500;
ll dp[M][LIM], p[M], cnt[M];

ll calc(int m, ll sumB, ll tot)
{
    if (tot - sumB == 0)
        return 0;
    ll prod = tot - sumB, sumA = 0;
    for (int i = 0; i < m; i++)
    {
        ll c = cnt[i];
        while (prod % p[i] == 0)
        {
            prod /= p[i];
            c--;
        }
        if (c < 0)
            return 0;
        sumA += c * p[i];
    }
    return (prod == 1 && sumA == tot - sumB) ? sumA : 0;
}

ll primetime(int cur, int m, ll sumB, ll tot)
{
    if (cur == m)
        return calc(m, sumB, tot);
    if (dp[cur][sumB] == -1)
    {
        ll res = 0, x = sumB;
        for (ll i = 0; x <= LIM && i <= cnt[cur]; i++, x += p[cur])
            res = max(res, primetime(cur + 1, m, x, tot));
        dp[cur][sumB] = res;
    }
    return dp[cur][sumB];
}

ll solve()
{
    int m;
    cin >> m;
    ll tot = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i] >> cnt[i];
        tot += p[i] * cnt[i];
    }
    memset(dp, -1, sizeof(dp));
    return primetime(0, m, 0, tot);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}