// https://codeforces.com/problemset/problem/370/A
// Rook, Bishop and King

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int color(int r, int c)
{
    if (r % 2 == c % 2)
        return 1;
    return 0;
}

int bfs(int r1, int c1, int r2, int c2)
{
    int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dc[8] = {1, 1, 0, -1, -1, -1, 0, 1}, moves = 0;
    vector<vector<bool>> vis(9, vector<bool>(9));
    queue<pair<int, int>> q;
    q.push({r1, c1});
    while (!q.empty())
    {
        int size = q.size();
        while (size-- > 0)
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first == r2 && cur.second == c2)
                return moves;
            if (vis[cur.first][cur.second])
                continue;
            vis[cur.first][cur.second] = true;
            for (int dir = 0; dir < 8; dir++)
            {
                int i = cur.first + dr[dir], j = cur.second + dc[dir];
                if (i > 0 && i <= 8 && j > 0 && j <= 8 && !vis[i][j])
                    q.push({i, j});
            }
        }
        moves++;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    // rook
    if (r1 == r2 && c1 == c2)
        cout << "0 ";
    else if (r1 == r2 || c1 == c2)
        cout << "1 ";
    else
        cout << "2 ";

    // bishop
    if (color(r1, c2) != color(r2, c2) || (r1 == r2 && c1 == c2))
        cout << "0 ";
    else if (abs(r1 - c1) == abs(r2 - c2))
        cout << "1 ";
    else
        cout << "2 ";

    // king
    cout << bfs(r1, c1, r2, c2) << "\n";
    return 0;
}