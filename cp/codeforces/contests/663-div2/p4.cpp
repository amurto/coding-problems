#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5, K = 5, inf = 1e7;
int dp[N][1 << K];

void rotate(vector<vector<char>> &grid, int &n, int &m)
{
    vector<vector<char>> mat(m, vector<char>(n));
    for (int j = 0, a = 0; j < m; j++, a++)
        for (int i = n - 1, b = 0; i >= 0; i--, b++)
            mat[a][b] = grid[i][j];
    grid = mat;
    swap(n, m);
}

bool valid(int mask, int e, int i, int j, int n, int m)
{
    if (i == 0 || j == 0)
        return true;
    int sum = e;
    if (n == 2)
    {
        for (int k = 4; k >= 2; k--)
            sum += ((mask >> k) & 1);
    }
    else
    {
        for (int k = 4; k >= 1; k--)
            if (k != 3)
                sum += ((mask >> k) & 1);
    }
    return sum & 1;
}

int dfs(vector<vector<char>> &grid, int cur, int mask, int n, int m)
{
    if (cur == n * m)
        return 0;
    if (dp[cur][mask] == -1)
    {

        int j = cur / n, i = cur % n, res = inf;
        int e = grid[i][j] - '0';
        for (int p = 0; p < 2; p++, e ^= 1)
            if (valid(mask, e, i, j, n, m))
                res = min(res, p + dfs(grid, cur + 1, mask >> 1 | (e << (K - 1)), n, m));
        dp[cur][mask] = res;
    }
    return dp[cur][mask];
}

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    if (n >= 4 && m >= 4)
        return -1;
    if (n == 1 || m == 1)
        return 0;
    if (n > m)
        rotate(grid, n, m);
    memset(dp, -1, sizeof(dp));
    int res = dfs(grid, 0, 0, n, m);
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}