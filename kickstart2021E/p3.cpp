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

void solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<pii>> h(n, vector<pii>(m)), v(n, vector<pii>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;)
        {
            if (grid[i][j] == '#')
                j++;
            else
            {
                int r = j;
                while (r < m && grid[i][r] != '#')
                    r++;
                for (int a = j, b = r - 1; a <= b; a++, b--)
                {
                    h[i][a] = {i, b};
                    h[i][b] = {i, a};
                }
                j = r;
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n;)
        {
            if (grid[i][j] == '#')
                i++;
            else
            {
                int r = i;
                while (r < n && grid[r][j] != '#')
                    r++;
                for (int a = i, b = r - 1; a <= b; a++, b--)
                {
                    v[a][j] = {b, j};
                    v[b][j] = {a, j};
                }
                i = r;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] || grid[i][j] == '#')
                continue;
            queue<pii> q;
            vector<pii> ids;
            vis[i][j] = true;
            ids.pb({i, j});
            q.push({i,j});
            while (!q.empty())
            {
                pii cur = q.front();
                pii h_id = h[cur.first][cur.second];
                pii v_id = v[cur.first][cur.second];
                q.pop();
                if (!vis[h_id.first][h_id.second])
                {
                    ids.pb(h_id);
                    vis[h_id.first][h_id.second] = true;
                    q.push(h_id);
                }
                if (!vis[v_id.first][v_id.second])
                {
                    ids.pb(v_id);
                    vis[v_id.first][v_id.second] = true;
                    q.push(v_id);
                }
            }
            char ch = '.';
            for (pii p : ids)
                if (grid[p.first][p.second] != '.')
                    ch = grid[p.first][p.second];
            for (pii p : ids)
                if (grid[p.first][p.second] != ch)
                {
                    res++;
                    grid[p.first][p.second] = ch;
                }
        }
    }
    cout << res << "\n";
    for (int i = 0; i < n; i++)
        cout << grid[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}