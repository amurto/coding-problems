// https://codeforces.com/contest/489/problem/F
// Special Matrices

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

int MOD;
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

int nc2(int x)
{
    return (x * (x - 1)) / 2;
}

int solve()
{
    int n, m;
    cin >> n >> m >> MOD;
    vector<int> cnt(3);
    if (m > 0)
    {
        vector<string> arr(m);
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            int c = 0;
            for (int i = 0; i < m; i++)
                c += (arr[i][j] == '1');
            if (c == 0)
                cnt[2]++;
            else if (c == 1)
                cnt[1]++;
        }
    }
    else
        cnt[2] = n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[cnt[1]][cnt[2]] = 1;
    for (int row = m; row < n; row++)
    {
        vector<vector<int>> tdp(n + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (dp[i][j] > 0)
                {
                    if (i >= 2)
                        tdp[i - 2][j] = add(tdp[i - 2][j], mul(nc2(i) % MOD, dp[i][j]));
                    if (j >= 2 && i + 2 <= n)
                        tdp[i + 2][j - 2] = add(tdp[i + 2][j - 2], mul(nc2(j) % MOD, dp[i][j]));
                    if (i >= 1 && j >= 1)
                        tdp[i][j - 1] = add(tdp[i][j - 1], mul(mul(i, j), dp[i][j]));
                }
            }
        }
        swap(dp, tdp);
    }
    return dp[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}