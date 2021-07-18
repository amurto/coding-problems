#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const ll inf = 1e17;

void rotateGrid(vector<vector<ll>> &grid, int &n, int &m)
{
    vector<vector<ll>> mat(m, vector<ll>(n));
    for (int j = 0, a = 0; j < m; j++, a++)
        for (int i = n - 1, b = 0; i >= 0; i--, b++)
            mat[a][b] = grid[i][j];
    grid = mat;
    swap(n, m);
}

ll op(vector<vector<ll>> &grid, int n, int m, ll c)
{
    ll res = inf;
    vector<vector<ll>> up(n, vector<ll>(m, inf)), down(n, vector<ll>(m, inf));

    for (int j = 0; j < m; j++)
    {
        ll mn = grid[0][j] + c;
        for (int i = 1; i < n; i++)
        {
            up[i][j] = mn;
            mn = min(mn, grid[i][j]) + c;
        }
        mn = grid[n - 1][j] + c;
        for (int i = n - 2; i >= 0; i--)
        {
            down[i][j] = mn;
            mn = min(mn, grid[i][j]) + c;
        }
    }
    for (int i = 0; i < n; i++)
    {
        res = min(res, min(up[i][0], down[i][0]) + grid[i][0]);
        ll mn = min(grid[i][0], min(up[i][0], down[i][0])) + c;
        for (int j = 1; j < m; j++)
        {
            res = min(res, mn + grid[i][j]);
            mn = min(mn, min(grid[i][j], min(up[i][j], down[i][j]))) + c;
        }
    }
    return res;
}

ll solve()
{
    int h, w;
    ll c, res = inf;
    cin >> h >> w >> c;
    vector<vector<ll>> grid(h, vector<ll>(w)), dis(h, vector<ll>(w, inf));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];
    for (int k = 0; k < 4; k++)
    {
        res = min(res, op(grid, h, w, c));
        rotateGrid(grid, h, w);
    }
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