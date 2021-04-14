#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 25;

class item
{
public:
    int vis = 0, p = 0, px = 0, ex = 0;
    item() {}
    item(int vis, int p, int px, int ex) : vis(vis), p(p), px(px), ex(ex) {}
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

item dp[N][N];
item bob(vector<string> &grid, int r, int c, int n, int m, int p, int q, int y, int dis)
{
    if (r >= n || c >= m)
        return item(1, 0, 0, 0);
    if (grid[r][c] == '2')
        return item(1, dis, 0, 0);
    if (grid[r][c] == 'x')
        return item(1, dis, 1, 1);
    if (dp[r][c].vis == 0)
    {
        item res = item(1, 0, 0, 0);
        // r,c -> r,c+1
        item i1 = bob(grid, r, c + 1, n, m, p, q, y, dis + 1);
        // r,c -> r+1,c
        item i2 = bob(grid, r + 1, c, n, m, p, q, y, dis + 1);
        res.p = mul(add(mul(p, i1.p), mul(q, i2.p)), inv(y));
        if (i1.ex == 1)
            res.px = add(res.px, mul(p, i1.px));
        if (i2.ex == 1)
            res.px = add(res.px, mul(q, i2.px));
        res.ex = max(i1.ex, i2.ex);
        if (res.ex == 1)
            res.px = mul(res.px, inv(y));
        dp[r][c] = res;
    }
    return dp[r][c];
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
                        dp[r][c] = item(0, 0, 0, 0);
                item res = bob(grid, i, j, n, m, p, q, y, 0);
                int cur_ans = res.p;
                if (res.ex == 1)
                    cur_ans = mul(cur_ans, inv(add(1, -res.px)));
                ans = add(ans, cur_ans);
            }
        }
    }
    ans = mul(ans, inv(cnt));
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