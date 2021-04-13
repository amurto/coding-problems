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

void rotate(vector<vector<char>> &grid, int &n, int &m)
{
    vector<vector<char>> mat(m, vector<char>(n));
    for (int j = 0, a = 0; j < m; j++, a++)
    {
        for (int i = n - 1, b = 0; i >= 0; i--, b++)
        {
            mat[a][b] = grid[i][j];
        }
    }
    grid = mat;
    swap(n, m);
}
int cad(vector<vector<int>> &dp, vector<vector<char>> &grid, int cur, int last, int n, int m)
{
    if (cur == n * m)
        return 0;
    if (dp[cur][last] == -1)
    {
        int res = 0, i = cur / m, j = cur % m;
        if (grid[i][j] == '*')
            res = add(res, cad(dp, grid, cur + 1, 0, n, m));
        else
        {
            for (int k = 1; k <= 2; k++)
            {
                res = add(res, cad(dp, grid, cur + 1, k, n, m));
                if (j > 0 && last == 2 && k == 2)
                    res = add(res, 1);
            }
        }
        dp[cur][last] = res;
    }
    return dp[cur][last];
}
int solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    int res = 0;
    vector<vector<int>> dp1(n * m, vector<int>(3, -1)), dp2(n * m, vector<int>(3, -1));
    res = add(res, cad(dp1, grid, 0, 0, n, m));
    rotate(grid, n, m);
    res = add(res, cad(dp2, grid, 0, 0, n, m));
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