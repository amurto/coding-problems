#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

class cell
{
public:
    int i, j, c;
    cell() {}
    cell(int i, int j, int c) : i(i), j(j), c(c) {}
};

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<string> grid(n);
    vector<vector<int>> vis(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    queue<cell> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int ni = i + di[dir], nj = j + dj[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && vis[ni][nj] == -1 && grid[ni][nj] == grid[i][j])
                {
                    vis[ni][nj] = 1;
                    q.push(cell(ni, nj, (grid[ni][nj] - '0') ^ 1));
                }
            }
        }
    }
    int itr = 2;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            cell cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int ni = cur.i + di[dir], nj = cur.j + dj[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && vis[ni][nj] == -1 && (grid[ni][nj] - '0') == cur.c)
                {
                    vis[ni][nj] = itr;
                    q.push(cell(ni, nj, cur.c ^ 1));
                }
            }
        }
        itr++;
    }
    for (int tc = 0; tc < t; tc++)
    {
        int i, j;
        ll p;
        cin >> i >> j >> p;
        i--;
        j--;
        if (vis[i][j] == -1 || p < vis[i][j])
            cout << grid[i][j] << "\n";
        else
        {
            int c = (grid[i][j] - '0') ^ 1;
            if ((p - vis[i][j]) % 2 == 0)
                cout << c << "\n";
            else
                cout << (c ^ 1) << "\n";
        }
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