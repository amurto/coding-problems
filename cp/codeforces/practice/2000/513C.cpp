// https://codeforces.com/contest/513/problem/C
// Second price auction

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5;
int vis[N][N][N];
int l[N], r[N];

double get_frac(int x, int y)
{
    return (1.0 * x) / (1.0 * y);
}

double dfs(vector<vector<vector<double>>> &dp, int b, int cur, int g, int e, int n)
{
    if (cur == n)
    {
        if (g == 0)
            return (e > 1) ? 1.0 : 0.0;
        else if (g == 1)
            return (e > 0) ? 1.0 : 0.0;
        return 0.0;
    }
    if (vis[cur][g][e] == -1)
    {
        vis[cur][g][e] = 0;
        double p = 0;
        if (g == 0 && r[cur] > b)
            p += get_frac(r[cur] - max(b, l[cur] - 1), r[cur] - l[cur] + 1) * dfs(dp, b, cur + 1, g + 1, e, n);
        if (l[cur] <= b && r[cur] >= b)
            p += get_frac(1, r[cur] - l[cur] + 1) * dfs(dp, b, cur + 1, g, e + 1, n);
        if (l[cur] < b)
            p += get_frac(min(r[cur] + 1, b) - l[cur], r[cur] - l[cur] + 1) * dfs(dp, b, cur + 1, g, e, n);
        dp[cur][g][e] = p;
    }
    return dp[cur][g][e];
}

double solve()
{
    int n, mn = 1e4 + 5, mx = 0;
    double res = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        mn = min(mn, l[i]);
        mx = max(mx, r[i]);
    }
    for (int i = mn; i <= mx; i++)
    {
        memset(vis, -1, sizeof(vis));
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(n)));
        res += 1.0 * i * dfs(dp, i, 0, 0, 0, n);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}