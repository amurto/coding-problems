// https://codeforces.com/contest/1102/problem/F
// Elongated Matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e9 + 5;
int dp[16][16][1 << 16], mx[16][16], nxt[16][16];

int dfs(vector<vector<int>> &grid, int n, int last, int f, int mask)
{
    if (__builtin_popcount(mask) == n)
        return nxt[f][last];
    if (dp[last][f][mask] == -1)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
            if (!((mask >> i) & 1))
                res = max(res, min(mx[last][i], dfs(grid, n, i, f, mask | (1 << i))));
        dp[last][f][mask] = res;
    }
    return dp[last][f][mask];
}

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int val = inf;
            for (int c = 0; c < m; c++)
                val = min(val, abs(grid[i][c] - grid[j][c]));
            mx[i][j] = mx[j][i] = val;
            int tmp = inf;
            for (int c = 0; c < m - 1; c++)
                tmp = min(tmp, abs(grid[j][c] - grid[i][c + 1]));
            nxt[i][j] = tmp;
            tmp = inf;
            for (int c = 0; c < m - 1; c++)
                tmp = min(tmp, abs(grid[i][c] - grid[j][c + 1]));
            nxt[j][i] = tmp;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dfs(grid, n, i, i, 1 << i));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}