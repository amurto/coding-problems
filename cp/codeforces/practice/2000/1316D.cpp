// https://codeforces.com/contest/1316/problem/D
// Nash Matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
string mark = "URDLX";
void dfs(vector<vector<pii>> &grid, vector<vector<char>> &res, int i, int j, int last, int n)
{
    res[i][j] = mark[last];
    for (int dir = 0; dir < 4; dir++)
    {
        int ni = i + di[dir], nj = j + dj[dir];
        if (ni > 0 && ni <= n && nj > 0 && nj <= n && grid[i][j] == grid[ni][nj] && res[ni][nj] == '*')
            dfs(grid, res, ni, nj, (dir + 2) % 4, n);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<pii>> grid(n + 1, vector<pii>(n + 1));
    vector<vector<char>> res(n + 1, vector<char>(n + 1, '*'));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j].first >> grid[i][j].second;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j].first == i && grid[i][j].second == j)
                dfs(grid, res, i, j, 4, n);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j].first != -1)
            {
                if (res[i][j] == '*')
                {
                    cout << "INVALID\n";
                    return;
                }
            }
            else
            {
                bool f = false;
                for (int dir = 0; !f && dir < 4; dir++)
                {
                    int ni = i + di[dir], nj = j + dj[dir];
                    if (ni > 0 && ni <= n && nj > 0 && nj <= n && grid[i][j] == grid[ni][nj])
                    {
                        f = true;
                        res[i][j] = mark[dir];
                    }
                }
                if (!f)
                {
                    cout << "INVALID\n";
                    return;
                }
            }
        }
    }
    cout << "VALID\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << res[i][j];
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