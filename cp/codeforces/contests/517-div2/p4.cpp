#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

string solve()
{
    int n, k, mx = -1;
    cin >> n >> k;
    string res = "";
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<vector<bool>> vis(n, vector<bool>(n));
    queue<pii> q;
    if (k == 0)
        q.push({0, 0});
    else
    {
        vector<vector<int>> dis(n, vector<int>(n)), dp(n, vector<int>(n, 2 * n));
        dp[0][0] = (grid[0][0] != 'a');
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dis[i][j] = i + j + 1;
                if (i + j > 0)
                {
                    int c = (grid[i][j] != 'a');
                    if (i - 1 >= 0)
                        dp[i][j] = min(dp[i][j], c + dp[i - 1][j]);
                    if (j - 1 >= 0)
                        dp[i][j] = min(dp[i][j], c + dp[i][j - 1]);
                }
                if (dp[i][j] == k)
                    mx = max(mx, dis[i][j]);
            }
        }
        if (mx == -1 || dp[n - 1][n - 1] <= k)
        {
            for (int i = 1; i < 2 * n; i++)
                res.pb('a');
            return res;
        }
        for (int i = 1; i <= mx; i++)
            res.pb('a');
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] == k && dis[i][j] == mx)
                {
                    if (i + 1 < n && !vis[i + 1][j])
                    {
                        vis[i + 1][j] = true;
                        q.push({i + 1, j});
                    }
                    if (j + 1 < n && !vis[i][j + 1])
                    {
                        vis[i][j + 1] = true;
                        q.push({i, j + 1});
                    }
                }
            }
        }
    }
    while (!q.empty())
    {
        char ch = 'z';
        queue<pii> tmp;
        while (!q.empty())
        {
            pii cur = q.front();
            q.pop();
            ch = min(ch, grid[cur.first][cur.second]);
            tmp.push(cur);
        }
        res.pb(ch);
        while (!tmp.empty())
        {
            pii cur = tmp.front();
            tmp.pop();
            if (grid[cur.first][cur.second] == ch)
            {
                if (cur.first + 1 < n && !vis[cur.first + 1][cur.second])
                {
                    vis[cur.first + 1][cur.second] = true;
                    q.push({cur.first + 1, cur.second});
                }
                if (cur.second + 1 < n && !vis[cur.first][cur.second + 1])
                {
                    vis[cur.first][cur.second + 1] = true;
                    q.push({cur.first, cur.second + 1});
                }
            }
        }
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