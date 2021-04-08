// https://codeforces.com/contest/510/problem/D
// Fox And Jumping

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 305, inf = 1e8;
vector<int> g[N];
int dp[N][N][1 << 9];

int jump(vector<int> &l, vector<int> &c, int st, int cur, int mask, int n)
{
    if (mask == 0)
        return 0;
    if (cur == n)
        return inf;
    if (dp[cur][st][mask] == -1)
    {
        int res = jump(l, c, st, cur + 1, mask, n), tmask = mask;
        for (int b = 0; b <= 9; b++)
            if (1 & (mask >> b))
                if (l[cur] % g[st][b] > 0)
                    tmask = tmask & ~(1 << b);
        res = min(res, c[cur] + jump(l, c, st, cur + 1, tmask, n));
        dp[cur][st][mask] = res;
    }
    return dp[cur][st][mask];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, res = inf;
    cin >> n;
    vector<int> l(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        int x = l[i];
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                while (x % j == 0)
                    x /= j;
                g[i].pb(j);
            }
        }
        if (x > 1)
            g[i].pb(x);
    }
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j = 0; j < g[i].size(); j++)
            mask |= (1 << j);
        res = min(res, c[i] + jump(l, c, i, i + 1, mask, n));
    }
    res == inf ? cout << "-1\n" : cout << res << "\n";
    return 0;
}