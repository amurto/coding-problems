#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 25, M = 25;

class item
{
public:
    int vis = 0, nume = 0, dene = 0, numx = 0, denx = 0, ex = 0;
    item() {}
    item(int vis, int nume, int dene, int numx, int denx, int ex) : vis(vis), nume(nume), dene(dene), numx(numx), denx(denx), ex(ex) {}
};

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

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int inv(int v)
{
    return power(v, MOD - 2, MOD);
}

item dp[N][M][N][M];
item bob(vector<string> &grid, int si, int sj, int cur, int n, int m, int p, int q, int y, int dis)
{
    int r = cur / m, c = cur % m;
    if (grid[r][c] == '2')
        return item(1, dis, 1, 0, 0, 0);
    if (grid[r][c] == 'x')
        return item(1, dis, 1, 1, 1, 1);
    if (dp[si][sj][r][c].vis == 0)
    {
        // r,c -> r+1,c
        item i1 = bob(grid, si, sj, cur + 1, n, m, p, q, y, dis + 1);
        // r,c -> r,c+1
        item i2 = bob(grid, si, sj, cur + m, n, m, p, q, y, dis + 1);
        item res = item(1, 0, 0, 0, 0, 0);
        res.nume = add(mul(p, i1.nume), mul(q, i2.nume));
        res.dene = add(mul(y, i1.dene), mul(y, i2.dene));
        if (i1.ex == 1)
        {
            res.ex = 1;
            res.numx = add(res.numx, mul(p, i1.numx));
            res.denx = add(res.denx, mul(y, i1.denx));
        }
        if (i2.ex == 1)
        {
            res.ex = 1;
            res.numx = add(res.numx, mul(q, i2.numx));
            res.denx = add(res.denx, mul(y, i2.denx));
        }
        dp[si][sj][r][c] = res;
    }
    return dp[si][sj][r][c];
}
int solve()
{
    int n, m, x, y, cnt = 0;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        cnt += count(grid[i].begin(), grid[i].end(), '1');
    }
    cin >> x >> y;
    int p = x, q = y - x, cur = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++, cur++)
        {
            if (grid[i][j] == '1')
            {
                for (int r = 0; r < n; r++)
                    for (int c = 0; c < m; c++)
                        dp[i][j][r][c] = item(0, 0, 0, 0, 0, 0);
                item res = bob(grid, i, j, cur, n, m, p, q, y, 0);
                res.dene = mul(cnt, res.dene);
                res.denx = mul(cnt, res.denx);
                int cur_ans = mul(res.nume, inv(res.dene));
                if (res.ex == 1)
                {
                    cur_ans = mul(cur_ans, res.denx);
                    cur_ans = mul(cur_ans, inv(add(res.denx, -res.numx)));
                }
                ans = add(ans, cur_ans);
            }
        }
    }
    return ans;
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