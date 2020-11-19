#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int happiness(vector<vector<int>> &grid, int m, int n)
{
    int di[4] = {1, 0, -1, 0}, dj[4] = {0, -1, 0, 1}, score[3] = {0, 120, 40}, h = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int nb = 0;
            for (int dir = 0; dir < 4; dir++)
            {
                int r = i + di[dir], c = j + dj[dir];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] > 0)
                    nb++;
            }
            h += score[grid[i][j]];
            if (grid[i][j] == 1)
                h -= nb * 30;
            else if (grid[i][j] == 2)
                h += nb * 20;
        }
    }
    return h;
}

int dfs(vector<vector<int>> &grid, int m, int n, int i, int e, int cur)
{
    if ((i == 0 && e == 0) || cur == m * n)
        return happiness(grid, m, n);
    int c0 = 0, c1 = 0, c2 = 0, r = cur / n, c = cur % n;
    cout << r << " " << c << "\n";
    c0 = dfs(grid, m, n, i, e, cur + 1);
    if (i > 0)
    {
        grid[r][c] = 1;
        c1 = dfs(grid, m, n, i - 1, e, cur + 1);
        grid[r][c] = 0;
    }
    if (e > 0)
    {
        grid[r][c] = 2;
        c2 = dfs(grid, m, n, i, e - 1, cur + 1);
        grid[r][c] = 0;
    }
    return max({c0, c1, c2});
}

int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount)
{
    vector<vector<int>> grid(m, vector<int>(n));
    return dfs(grid, m, n, introvertsCount, extrovertsCount, 0);
}

int main()
{
    int m = 3, n = 4, introvertsCount = 6, extrovertsCount = 3;
    cout << getMaxGridHappiness(m, n, introvertsCount, extrovertsCount) << "\n";
    // for (int i = 0; i < m * n; i++)
    //     cout << i / n << " " << i % n << "\n";
    return 0;
}