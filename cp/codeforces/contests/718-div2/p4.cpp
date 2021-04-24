#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e8;
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

void solve()
{
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<vector<vector<int>>> g(n, vector<vector<int>>(m, vector<int>(4)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            cin >> x;
            g[i][j][0] = g[i][j + 1][2] = x;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            g[i][j][1] = g[i + 1][j][3] = x;
        }
    }
    if (k & 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << "-1 ";
            cout << "\n";
        }
        return;
    }
    int h = k / 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(h + 1)));
    for (int p = 1; p <= h; p++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j][p] = inf;
                for (int dir = 0; dir < 4; dir++)
                {
                    int r = i + di[dir], c = j + dj[dir];
                    if (r >= 0 && r < n && c >= 0 && c < m)
                        dp[i][j][p] = min(dp[i][j][p], dp[r][c][p - 1] + 2 * g[i][j][dir]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << dp[i][j][h] << " ";
        cout << "\n";
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