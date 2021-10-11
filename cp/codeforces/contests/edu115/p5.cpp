#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<pair<int, int>, int> piii;
#define pb push_back

// 0 -> from left
// 1 -> from above
void solve()
{
    int n, m, q, x, y;
    cin >> n >> m >> q;
    ll sum = 0;
    vector<vector<int>> grid(n, vector<int>(m, 1));
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(2)));
    vector<vector<ll>> ways(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i - 1 >= 0)
                dp[i][j][1] = dp[i - 1][j][0] + 1;
            if (j - 1 >= 0)
                dp[i][j][0] = dp[i][j - 1][1] + 1;
            ways[i][j] = dp[i][j][0] + dp[i][j][1] + 1;
            sum += ways[i][j];
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        grid[x][y] ^= 1;
        queue<piii> q;
        q.push({{x, y}, 0});
        q.push({{x, y}, 1});
        while (!q.empty())
        {
            piii cur = q.front();
            q.pop();
            int px = cur.first.first, py = cur.first.second, dir = cur.second;
            sum -= ways[px][py];
            if (grid[px][py])
            {
                if (dir == 0)
                {
                    if (py - 1 >= 0)
                        dp[px][py][0] = dp[px][py - 1][1] + grid[px][py - 1];
                }
                else
                {
                    if (px - 1 >= 0)
                        dp[px][py][1] = dp[px - 1][py][0] + grid[px - 1][py];
                }
                ways[px][py] = dp[px][py][0] + dp[px][py][1] + grid[px][py];
            }
            else
            {
                dp[px][py][0] = dp[px][py][1] = 0;
                ways[px][py] = 0;
            }
            sum += ways[px][py];
            if (dir == 0)
            {
                if (px + 1 < n)
                    q.push({{px + 1, py}, 1});
            }
            else
            {
                if (py + 1 < m)
                    q.push({{px, py + 1}, 0});
            }
        }
        cout << sum << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}