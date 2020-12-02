// https://www.spoj.com/problems/QUEEN/
// QUEEN - Wandering Queen

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

char board[1001][1001];
int vis[1001][1001];
int di[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int bfs(int si, int sj, int n, int m)
{
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    vis[si][sj] = 256;
    q.push({si, sj});
    int d = 1;
    while (!q.empty())
    {
        int len = q.size();
        while (len-- > 0)
        {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int nr = r + di[dir], nc = c + dj[dir], mask = 1 << dir;
                while (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] != 'X' && !(vis[nr][nc] & mask))
                {
                    if (board[nr][nc] == 'F')
                        return d;

                    // main optimization
                    // if cell was visited by some direction earlier, dont push to queue
                    if (vis[nr][nc] == 0)
                        q.push({nr, nc});
                    vis[nr][nc] |= mask;
                    nr += di[dir];
                    nc += dj[dir];
                }
            }
        }
        d++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m, si = 0, sj = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        cout << bfs(si, sj, n, m) << "\n";
    }
    return 0;
}