// https://www.spoj.com/problems/CLEANRBT/
// CLEANRBT - Cleaning Robot

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 20, inf = 1e6;
char grid[N][N];
int dis[10][10], dp[10][1 << 10], s[10], di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

int bfs(int si, int sj, int ti, int tj, int r, int c)
{
    int m = 1;
    vector<vector<bool>> vis(r, vector<bool>(c));
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            pair<int, int> p = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int i = p.first + di[dir], j = p.second + dj[dir];
                if (i < 0 || i >= r || j < 0 || j >= c)
                    continue;
                if (i == ti && j == tj)
                    return m;
                if (!vis[i][j] && grid[i][j] != 'x')
                {
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        m++;
    }
    return -1;
}

int clean(int cur, int mask, int dirty, int r, int c)
{
    if (mask + 1 == (1 << dirty))
        return 0;
    if (dp[cur][mask] == -1)
    {
        int res = inf;
        for (int i = 0; i < dirty; i++)
        {
            if (mask & (1 << i))
                continue;
            res = min(res, dis[cur][i] + clean(i, mask | (1 << i), dirty, r, c));
        }
        dp[cur][mask] = res;
    }
    return dp[cur][mask];
}

int solve(int r, int c)
{
    int si, sj;
    vector<pair<int, int>> obs;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'o')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == '*')
                obs.pb({i, j});
        }
    }
    for (int i = 0; i < obs.size(); i++)
    {
        s[i] = bfs(si, sj, obs[i].first, obs[i].second, r, c);
        if (s[i] == -1)
            return -1;
        for (int j = i + 1; j < obs.size(); j++)
        {
            dis[i][j] = dis[j][i] = bfs(obs[i].first, obs[i].second, obs[j].first, obs[j].second, r, c);
            if (dis[i][j] == -1)
                return -1;
        }
    }
    int res = inf, dirty = obs.size();
    for (int i = 0; i < dirty; i++)
        res = min(res, s[i] + clean(i, (1 << i), dirty, r, c));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r, c;
    while (cin >> c >> r && r + c > 0)
        cout << solve(r, c) << "\n";
    return 0;
}