// https://codeforces.com/contest/1238/problem/E
// Keyboard Purchase

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

const int inf = 1e9 + 7;

void dfs(vector<vector<int>> &g, vector<int> &mask_sum, int mask, int sum, int cur, int m)
{
    if (cur == m)
    {
        mask_sum[mask] = sum;
        return;
    }
    int tmp = sum;
    for (int i = 0; i < cur; i++)
        if ((mask >> i) & 1)
            sum += g[cur][i];
    dfs(g, mask_sum, mask, sum, cur + 1, m);
    swap(tmp, sum);
    for (int i = 0; i < cur; i++)
        if (!((mask >> i) & 1))
            sum += g[cur][i];
    dfs(g, mask_sum, mask | (1 << cur), sum, cur + 1, m);
}

int solve()
{
    int n, m;
    string str;
    cin >> n >> m >> str;
    vector<vector<int>> g(m, vector<int>(m));
    for (int i = 1; i < n; i++)
    {
        if (str[i - 1] != str[i])
        {
            g[str[i - 1] - 'a'][str[i] - 'a']++;
            g[str[i] - 'a'][str[i - 1] - 'a']++;
        }
    }
    vector<int> mask_sum(1 << m), dp(1 << m, inf);
    dfs(g, mask_sum, 0, 0, 0, m);
    dp[0] = 0;
    for (int mask = 1; mask < (1 << m); mask++)
        for (int b = 0; b < m; b++)
            if ((mask >> b) & 1)
                dp[mask] = min(dp[mask], mask_sum[mask] + dp[mask ^ (1 << b)]);
    return dp[(1 << m) - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}