#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dp[18][1 << 16][18];

void construct(vector<vector<int>> &grid, int mask, int h, int w)
{
    int cell = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++, cell++)
            if ((mask & (1 << cell)) > 0)
                grid[i][j] = 1;
}

int reconstruct(vector<vector<int>> &grid, int h, int w)
{
    int mask = 0, cell = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++, cell++)
            mask |= (grid[i][j] << cell);
    return mask;
}

int hanjo(int rem, int mask, int cell, int h, int w)
{
    if (rem == 0)
        return 1;
    if (cell == h * w)
        return 0;
    if (dp[rem][mask][cell] == -1)
    {
        vector<vector<int>> grid(h, vector<int>(w));
        construct(grid, mask, h, w);
        int r = cell / w;
        int c = cell % w;
        dp[rem][mask][cell] = hanjo(rem, mask, cell + 1, h, w);
        if (grid[r][c] == 0)
        {
            grid[r][c] = 1;
            if (c + 1 < w && grid[r][c + 1] == 0)
            {
                grid[r][c + 1] = 1;
                dp[rem][mask][cell] += hanjo(rem - 1, reconstruct(grid, h, w), cell + 1, h, w);
                grid[r][c + 1] = 0;
            }
            if (r + 1 < h && grid[r + 1][c] == 0)
            {
                grid[r + 1][c] = 1;
                dp[rem][mask][cell] += hanjo(rem - 1, reconstruct(grid, h, w), cell + 1, h, w);
                grid[r + 1][c] = 0;
            }
        }
    }
    return dp[rem][mask][cell];
}

int solve()
{
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    memset(dp, -1, sizeof(dp));
    return hanjo(a, 0, 0, h, w);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}