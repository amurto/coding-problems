#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int M = 100, P = 1e5 + 5;
int dp[M][P], p[M], cnt[M];

int primetime(int cur, int m, int val)
{
    if (cur == m)
    {
        if (val == 1)
            return 0;
        int sum = 0, x = val;
        for (int i = 0; i < m; i++)
        {
            int c = cnt[i];
            while (val % p[i] == 0)
            {
                val /= p[i];
                c--;
            }
            sum += c * p[i];
        }
        if (sum == x)
            cout << sum << "\n";
        return sum == x ? x : 0;
    }
    if (dp[cur][val] == -1)
    {
        int res = 0, x = val;
        for (int i = 0; i <= cnt[cur]; i++, x *= p[cur])
            res = max(res, primetime(cur + 1, m, x));
        dp[cur][val] = res;
    }
    return dp[cur][val];
}

int solve()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i] >> cnt[i];
    memset(dp, -1, sizeof(dp));
    return primetime(0, m, 1);
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