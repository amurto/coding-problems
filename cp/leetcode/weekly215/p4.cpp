#include <bits/stdc++.h>
using namespace std;

// dp with bitmasking for subsets
int dp[64][64][7][7][25];
int happiness(int inmask, int exmask, int n, int row, int col, int c)
{
    int h = 0, up = (1 << (n - 1));
    if (row > 0 && (inmask & up))
        h += c - 30;
    if (col > 0 && (inmask & 1))
        h += c - 30;

    if (row > 0 && (exmask & up))
        h += c + 20;
    if (col > 0 && (exmask & 1))
        h += c + 20;
    return h;
}

int dfs(int inmask, int exmask, int m, int n, int iv, int ev, int cur)
{
    int row = cur / n, col = cur % n;
    if (row >= m)
        return 0;
    if (dp[inmask][exmask][iv][ev][cur] == -1)
    {
        int ninmask = (inmask << 1) & 63, nexmask = (exmask << 1) & 63, c0 = 0, c1 = 0, c2 = 0;
        c0 = dfs(ninmask, nexmask, m, n, iv, ev, cur + 1);
        if (iv > 0)
            c1 = 120 + happiness(inmask, exmask, n, row, col, -30) + dfs(ninmask + 1, nexmask, m, n, iv - 1, ev, cur + 1);
        if (ev > 0)
            c2 = 40 + happiness(inmask, exmask, n, row, col, 20) + dfs(ninmask, nexmask + 1, m, n, iv, ev - 1, cur + 1);
        dp[inmask][exmask][iv][ev][cur] = max({c0, c1, c2});
    }
    return dp[inmask][exmask][iv][ev][cur];
}

int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount)
{
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, m, n, introvertsCount, extrovertsCount, 0);
}

int main()
{
    int m = 2, n = 2, introvertsCount = 4, extrovertsCount = 0;
    cout << getMaxGridHappiness(m, n, introvertsCount, extrovertsCount) << "\n";
    return 0;
}