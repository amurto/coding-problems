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

int solve()
{
    int n, m, res = 25;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1)), pre(n + 1, vector<int>(m + 1)), cols(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
            grid[i][j] = str[j - 1] - '0';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            pre[i][j] = grid[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            cols[i][j] = cols[i - 1][j] + (grid[i][j] ^ 1);
    for (int r2 = 5; r2 <= n; r2++)
    {
        for (int r1 = 1; r1 <= r2 - 4; r1++)
        {
            vector<int> mn(m + 1);
            mn[0] = n + 5;
            for (int j = 1; j <= m; j++)
                mn[j] = min(mn[j - 1] + pre[r2 - 1][j] - pre[r2 - 1][j - 1] - pre[r1][j] + pre[r1][j - 1] + (grid[r1][j] ^ 1) + (grid[r2][j] ^ 1), cols[r2 - 1][j] - cols[r1][j]);
            for (int j = 4; j <= m; j++)
                res = min(res, mn[j - 3] + cols[r2 - 1][j] - cols[r1][j] + pre[r2 - 1][j - 1] - pre[r2 - 1][j - 3] - pre[r1][j - 1] + pre[r1][j - 3] + 4 - grid[r1][j - 1] - grid[r1][j - 2] - grid[r2][j - 1] - grid[r2][j - 2]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}