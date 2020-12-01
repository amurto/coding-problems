// https://www.spoj.com/problems/QUEEN/
// QUEEN - Wandering Queen

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool vis[1001][1001][8];
int di[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int bfs(vector<vector<char>> &board, int n, int m)
{
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'S')
            {
                q.push({i, j});
                for (int k = 0; k < 8; k++)
                    vis[i][j][k] = true;
                break;
            }
        }
    }
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
                int nr = r + di[dir];
                int nc = c + dj[dir];
                while (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] != 'X' && !vis[nr][nc][dir])
                {
                    if (board[nr][nc] == 'F')
                    {
                        return d;
                    }
                    vis[nr][nc][dir] = true;
                    q.push({nr, nc});
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        cout << bfs(board, n, m) << "\n";
    }
    return 0;
}