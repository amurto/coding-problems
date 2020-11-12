#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

int bfs(vector<vector<char>> &mat, int h, int w, int si, int sj)
{
    int moves = 0;
    vector<vector<bool>> vis(h, vector<bool>(w));
    queue<pair<int, int>> q;
    q.push({si, sj});
    while (!q.empty())
    {
        int size = q.size();
        while (size-- > 0)
        {
            int ci = q.front().first, cj = q.front().second;
            q.pop();
            if (vis[ci][cj])
                continue;
            vis[ci][cj] = true;
            for (int dir = 0; dir < 4; dir++)
            {
                int i = ci + di[dir], j = cj + dj[dir];
                if (i >= 0 && i < h && j >= 0 && j < w && mat[i][j] == '.' && !vis[i][j])
                    q.push({i, j});
            }
        }
        moves++;
    }
    return moves-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> mat(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> mat[i][j];
    int res = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (mat[i][j] == '.')
                res = max(res, bfs(mat, h, w, i, j));
    cout << res << "\n";
    return 0;
}