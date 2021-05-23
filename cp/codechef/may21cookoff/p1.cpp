#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e3 + 5;
ll grid[N][N], h[N][N], v[N][N];

ll solve()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll res = v[x2][y1] - v[x1 - 1][y1] + h[x2][y2] - h[x2][y1 - 1] - grid[x2][y1];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(grid, 0, sizeof(grid));
    memset(h, 0, sizeof(h));
    memset(v, 0, sizeof(v));
    for (int i = 1; i < N; i++)
        grid[i][1] = grid[i - 1][1] + i;
    for (int i = 1; i < N; i++)
        for (int j = 2, c = i; j < N; j++, c++)
            grid[i][j] = grid[i][j - 1] + c;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            v[i][j] = h[i][j] = grid[i][j];
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            h[i][j] += h[i][j - 1];
    for (int j = 1; j < N; j++)
        for (int i = 1; i < N; i++)
            v[i][j] += v[i - 1][j];
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}