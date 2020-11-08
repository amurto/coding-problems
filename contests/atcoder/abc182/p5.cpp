#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

bool valid(int &r, int &c, int &h, int &w)
{
    return (r > 0 && r <= h && c > 0 && c <= w);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w, n, m, a, b, c, d, r, c;
    cin >> h >> w;
    vector<vector<int>> grid(h + 1, vector<int>(w + 1));
    vector<vector<bool>> vis(h + 1, vector<bool>(w + 1));
    cin >> n >> m;
    queue<piii> q;
    int res = n;
    // 1 for bulb
    while (n-- > 0)
    {
        cin >> a >> b;
        grid[a][b] = 1;
        for (int dir = 0; dir < 4; dir++)
        {
            r = r + di[dir];
            c = c + dj[dir];
            if (valid(r, c, h, w))
                q.push({r, c});
        }
    }

    // 2 for block
    while (m-- > 0)
    {
        cin >> c >> d;
        grid[c][d] = 2;
    }
    int res = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (grid[i][j] != 1)
                continue;
            if (!vis[i][j])
                res++;
            for (int dir = 0; dir < 4; dir++)
            {
                int r = i + di[dir], c = j + dj[dir];
                while (valid(r, c, h, w) && grid[r][c] < 2)
                {
                    if (!vis[r][c])
                        res++;
                    vis[r][c] = true;
                    r += di[dir];
                    c += dj[dir];
                }
            }
        }
    }
    cout << res << "\n";
    return 0;
}