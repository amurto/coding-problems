// https://codeforces.com/contest/1225/problem/E
// Rock Is Push

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

const int MOD = 1e9 + 7;

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1)), h(n + 1, vector<int>(m + 1)), v(n + 1, vector<int>(m + 1)), dp(n + 1, vector<int>(m + 1)), v_jump(n + 1, vector<int>(m + 1)), h_jump(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
            grid[i][j] = (str[j - 1] == 'R');
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            h_jump[i][j] = j;
        int rocks = 0;
        for (int j = m; j > 0; j--)
        {
            if (m - rocks >= j)
                h_jump[i][m - rocks] = j;
            rocks += grid[i][j];
        }
        for (int j = m - 1; j > 0; j--)
            h_jump[i][j] = min(h_jump[i][j], h_jump[i][j + 1]);
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
            v_jump[i][j] = i;
        int rocks = 0;
        for (int i = n; i > 0; i--)
        {
            if (n - rocks >= i)
                v_jump[n - rocks][j] = i;
            rocks += grid[i][j];
        }
        for (int i = n - 1; i > 0; i--)
            v_jump[i][j] = min(v_jump[i][j], v_jump[i + 1][j]);
    }
    dp[1][1] = 1;
    v[1][1] = 1;
    h[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i + j != 2)
            {
                h[i][j] = add(v[i][j - 1], -v[i][h_jump[i][j] - 1]);
                v[i][j] = add(h[i - 1][j], -h[v_jump[i][j] - 1][j]);
                dp[i][j] = add(h[i][j], v[i][j]);
                h[i][j] = add(h[i][j], h[i - 1][j]);
                v[i][j] = add(v[i][j], v[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}