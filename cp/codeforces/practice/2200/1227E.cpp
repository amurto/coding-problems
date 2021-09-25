// https://codeforces.com/contest/1227/problem/E
// Arson In Berland Forest

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

// king moves
int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<int>> cells(n, vector<int>(m)), vis(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    queue<pii> q;
    vector<pii> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'X')
            {
                int cnt=0;
                for (int dir = 0; dir < 8; dir++)
                {
                    int ni = i + di[dir], nj = j + dj[dir];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 'X')
                        cnt++;
                }
                if (cnt < 8)
                {
                    q.push({i, j});
                    st.pb({i, j});
                }
            }
        }
    }
    for (pii p : st)
        grid[p.first][p.second] = '.';
    int t = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz > 0)
        {
            pii cur = q.front();
            cells[cur.first][cur.second] = t;
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int ni = cur.first + di[dir], nj = cur.second + dj[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 'X')
                {
                    grid[ni][nj] = '.';
                    q.push({ni, nj});
                }
            }
            sz--;
        }
        t++;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (cells[i][j] == t - 1)
                grid[i][j] = 'X';
    cout << t - 1 << "\n";
    for (int i = 0; i < n; i++)
        cout << grid[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}