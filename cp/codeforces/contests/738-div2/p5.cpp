#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5, MOD = 998244353;
// O(n)
vector<int> lp(N + 1), pr;
int mob[N];
void mobius()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
            mob[i] = 1;
        else
        {
            if (lp[i / lp[i]] == lp[i])
                mob[i] = 0;
            else
                mob[i] = -1 * mob[i / lp[i]];
        }
    }
}

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

int f(vector<int> &dp, int p, int v)
{
    if (v < 0)
        return 0;
    v = (v / p) * p;
    return dp[v];
}

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    int sum = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int p = 1; p <= m; p++)
    {
        if (mob[p] != 0)
        {
            dp[0][0] = 1;
            for (int j = p; j <= m; j += p)
                dp[0][j] = dp[0][j - p];
            int c = (m / p) * p;
            for (int i = 1; i <= n; i++)
            {
                for (int j = p; j <= m; j += p)
                {
                    dp[i][j] = 0;
                    if (j >= l[i])
                        dp[i][j] = add(f(dp[i - 1], p, j - l[i]), -f(dp[i - 1], p, j - r[i] - 1));
                    dp[i][j] = add(dp[i][j], dp[i][j - p]);
                }
            }
            sum = add(sum, mob[p] * dp[n][c]);
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mobius();
    cout << solve() << "\n";
    return 0;
}