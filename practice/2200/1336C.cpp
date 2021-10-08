// https://codeforces.com/contest/1336/problem/C
// Kaavi and Magic Spell

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

const int MOD = 998244353;

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

int solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length(), res = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        if ((i < m && s[0] == t[i]) || i >= m)
            dp[i][i] = 1;
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if ((i < m && s[j - i] == t[i]) || i >= m)
                dp[i][j] = add(dp[i][j], dp[i + 1][j]);
            if ((j < m && s[j - i] == t[j]) || j >= m)
                dp[i][j] = add(dp[i][j], dp[i][j - 1]);
        }
    }
    for (int i = m - 1; i < n; i++)
        res = add(res, dp[0][i]);
    return mul(res, 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}